#include <iostream>
#include <cstring>
#include <pthread.h>

#include <bobcat/sharedmemory>
#include <bobcat/exception>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << 
            "Argument:\n"
            "   c: create a shared memory segment, display its ID\n" 
            "   k <id>: kill shared memory segment <id>\n"
            "   l <id>: lock a SharedMutex in shared memory segment <id>\n"
            "   L <id>: create mutex, condition variable and count in "
                                                            "ID <id>\n"
            "   W <id>: condition wait for the mutex in shared memory "
                                                            "segment <id>\n"
            "   w <id>: wait for a lock set by 'l' to be released "
                                                            "(id = <id>)\n"
        ;
        return 0;
    }

    switch (argv[1][0])
    {
        case 'c':
        {
            SharedMemory shmem(1, SharedMemory::kB);

            void *ptr = shmem.ptr();
            cout << "ID = " << shmem.id() << ", data at " << ptr << '\n' <<
                    shmem << endl;
            break;
        }

        case 'l':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.seek(sizeof(SharedMutex));
            shmem.seek(0);
            SharedMutex *smPtr = new (shmem.ptr()) SharedMutex();
            smPtr->lock();
            cout << "Press enter to release the lock ";
            cin.ignore(1000, '\n');
            smPtr->unlock();
            break;
        }
            
        case 'L':
        {
            SharedMemory shmem(stoll(argv[2]));

                // room for the variables
            shmem.seek(sizeof(pthread_mutex_t) + sizeof(int) + 
                        sizeof(pthread_cond_t));

                // set up the pointers to the variables
            shmem.seek(0);
            pthread_mutex_t *mPtr = reinterpret_cast<pthread_mutex_t *>
                                            (shmem.ptr());
            pthread_cond_t *cPtr = reinterpret_cast<pthread_cond_t *>
                                    (shmem.ptr() + sizeof(pthread_mutex_t));
            int *iPtr = reinterpret_cast<int *>
                                    (shmem.ptr() + sizeof(pthread_mutex_t) +
                                                   sizeof(pthread_cond_t));

                // initialize the mutex
            pthread_mutexattr_t mutex_attr;
            pthread_mutexattr_init(&mutex_attr);
            pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
            pthread_mutex_init(mPtr, &mutex_attr);

                // initialize the condition
            pthread_condattr_t cond_attr;
            pthread_condattr_init(&cond_attr);
            pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
            pthread_cond_init(cPtr, &cond_attr);

                // initialize the variable
            memset(iPtr, 0, sizeof(int));

            if (pthread_mutex_lock(mPtr) != 0)
                throw Exception() << "Mutex failed to lock";

            cout << "Press enter to release the lock ";
            cin.ignore(1000, '\n');

                // set the variable to check
            *iPtr = 1;

                // signal
            pthread_cond_signal(cPtr);

                // unlock
            pthread_mutex_unlock(mPtr);

            break;
        }
            
        case 'W':
        {
            SharedMemory shmem(stoll(argv[2]));

                // room for the variables
            shmem.seek(sizeof(pthread_mutex_t) + sizeof(int) + 
                        sizeof(pthread_cond_t));

                // set up the pointers to the variables
            shmem.seek(0);
            pthread_mutex_t *mPtr = reinterpret_cast<pthread_mutex_t *>
                                            (shmem.ptr());
            pthread_cond_t *cPtr = reinterpret_cast<pthread_cond_t *>
                                    (shmem.ptr() + sizeof(pthread_mutex_t));
            int *iPtr = reinterpret_cast<int *>
                                    (shmem.ptr() + sizeof(pthread_mutex_t) +
                                                   sizeof(pthread_cond_t));

                // obtain the lock
            if (pthread_mutex_lock(mPtr) != 0)
                throw Exception() << "Mutex failed to lock";

            while (*iPtr == 0)
                pthread_cond_wait(cPtr, mPtr);

                // unlock
            pthread_mutex_unlock(mPtr);
            
            break;
        }
            
        case 'k':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.kill();
            break;
        }

        case 'w':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.seek(0);
            SharedMutex *smPtr = reinterpret_cast<SharedMutex *>(shmem.ptr());
            smPtr->lock();
            cout << "Obtained the lock. Now releasing it again\n";
            smPtr->unlock();
            break;
        }
            
    }
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << endl;
}



