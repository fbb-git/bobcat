#include <iostream>

#include <bobcat/sharedcondition>
#include <bobcat/sharedmemory>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << 
            "Argument:\n"
            "   c: create a shared memory segment + SharedCondition "
                                                    ", display ID\n" 
            "   k <id>: kill shared memory segment <id>\n"
            "   m <id>: show a message every 5 secs, otherwise wait until\n"
            "           being notified in segment <id>\n"
            "   w <id>: wait until being notified in segment <id>\n"
            "   n <id>: notify the SharedCondition in segment ID <id>\n"
        ;
        return 0;
    }

    switch (argv[1][0])
    {
        case 'c':
        {
            SharedMemory shmem(1, SharedMemory::kB);

            void *ptr = shmem.ptr();
            cout << "Before: " << shmem.showmanyc() << '\n';
            shmem.seek(sizeof(SharedCondition) - 1);
            shmem.put(0);
            cout << "After: " << shmem.showmanyc() << '\n';
            new (ptr) SharedCondition();

            cout << "ID = " << shmem.id() << ", data at " << ptr << '\n' <<
                    shmem << endl;
            break;
        }

        case 'k':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.kill();
            break;
        }

        case 'm':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.seek(0);
            SharedCondition *scPtr = 
                            reinterpret_cast<SharedCondition *>(shmem.ptr());

            scPtr->lock();
            cout << "Obtained the lock. Now waiting for a notification\n";
        
            while (true)
            {
                switch (scPtr->wait_for(chrono::seconds(5)))
                {
                    case cv_status::timeout:
                        cout << "Waited for 5 seconds\n\n";
                    break;

                    case cv_status::no_timeout:
                        cout << "Received the notification. Now unlocking.\n";
                        scPtr->unlock();
                    return 0;
                }
            }
        }
            
        case 'n':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.seek(0);
            SharedCondition *scPtr = 
                            reinterpret_cast<SharedCondition *>(shmem.ptr());
            cout << "Notifying the other after Enter ";
            cin.ignore(1000, '\n');
            scPtr->lock();
            cout << "Obtained the lock. Now notifying the other";
            scPtr->notify();
            cout << "Sent the notification. Now unlocking.\n";
            scPtr->unlock();
            break;
        }
            
        case 'w':
        {
            SharedMemory shmem(stoll(argv[2]));
            shmem.seek(0);
            SharedCondition *scPtr = 
                            reinterpret_cast<SharedCondition *>(shmem.ptr());
            scPtr->lock();
            cout << "Obtained the lock. Now waiting for a notification\n";
            scPtr->wait();
            cout << "Received the notification. Now unlocking.\n";
            scPtr->unlock();
            break;
        }
            
    }
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << endl;
}

