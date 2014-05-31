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
            "   n <id>: notify the SharedCondition in segment ID <id>\n"
        ;
        return 0;
    }

    switch (argv[1][0])
    {
        case 'c':
        {
            SharedMemory shmem(1, SharedMemory::kB);

            SharedCondition cond = SharedCondition::create(shmem);   

            void *ptr = shmem.ptr();

            cout << "ID = " << shmem.id() << ", SharedCondition at " << 
                    cond.offset() << endl;
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
            SharedCondition cond = SharedCondition::attach(shmem);

            cond.lock();
            cout << "Obtained the lock. Now waiting for a notification\n";
        
            while (true)
            {
                switch (cond.wait_for(chrono::seconds(5)))
                {
                    case cv_status::timeout:
                        cout << "Waited for 5 seconds\n\n";
                    break;

                    case cv_status::no_timeout:
                        cond.unlock();
                        cout << "Received the notification. Unlocked.\n";
                    return 0;
                }
            }
        }
            
        case 'w':
        {
            SharedMemory shmem(stoll(argv[2]));
            SharedCondition cond = SharedCondition::attach(shmem);

            cond.lock();
            cout << "Obtained the lock. Now waiting for a notification\n";
        
            cond.wait();
            cout << "Received the notification. Unlocking.\n";

            cond.unlock();
            break;
        }
            
        case 'n':
        {
            SharedMemory shmem(stoll(argv[2]));

            SharedCondition cond = SharedCondition::attach(shmem);

            cout << "Notifying the other after Enter ";
            cin.ignore(1000, '\n');

            cond.lock();
            cout << "Obtained the lock. Now notifying the other\n";
            cond.notify();
            cout << "Sent the notification. Now unlocking.\n";
            cond.unlock();
            break;
        }

    }
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << endl;
}

