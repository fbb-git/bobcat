#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>

#include <bobcat/process>
#include <bobcat/a2x>


pid_t discontinue(pid_t procId);

extern char **environ;

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "a.out sleep-1 sleep-2\n"
            "\n";
        return 1;
    }

    pid_t p1 = fork();
    if (p1 < 0)
    {
        cout << "Fork 1 failed\n";
        return 1;
    }

    if (p1 == 0)        // child runs the process
    {
//        char *name[] = {argv[1], 0};
//        cout << "Child 1 starts " << argv[1] << endl;
//        execve(name[0], name, environ);
//        cout << "Child 1 failed\n";
//        return 1;

        size_t sleepTime = A2x(argv[1]);
        cout << "Child 1 sleeps for " << sleepTime << "secs\n";
        sleep(sleepTime);
        cout << "Child 1 wakes up\n";
        return 0;       // stop after waking up
    }

    cout << "Started process 1: " << p1 << endl;

    // parent process continues

    pid_t p2 = fork();  // child waits at most arg2 seconds
    if (p2 < 0)
    {
        cout << "Fork 2 failed\n";
        p1 = discontinue(p1);
        return 1;
    }

    if (p2 == 0)        // child runs the process
    {
        size_t sleepTime = A2x(argv[2]);
        cout << "Child 2 sleeps for " << sleepTime << "secs\n";
        sleep(sleepTime);
        cout << "Child 2 wakes up\n";
        return 0;       // stop after waking up
    }

    cout << "Started sleeper process 2: " << p2 << endl;

    string cmd;
    while (p1 || p2)
    {
        cout << "Enter a command\n";
        getline(cin, cmd);
        cout << "Command entered: " << cmd << endl;
        
        if (p1)
        {
            if (waitpid(p1, 0, WNOHANG) > 0)    // p1 has changed
            {
                cout << "Process 1 (" << p1 << ") has stopped\n";
                p1 = 0;
                p2 = discontinue(p2);
            }
        }                
        if (p2)
        {
            if (waitpid(p2, 0, WNOHANG) > 0)    // p1 has changed
            {
                cout << "Process 2 (" << p2 << ") has stopped\n"
                        "Forcefully end process 1 (" << p1 << ")\n";

                p2 = 0;
                p1 = discontinue(p1);
            }
        }                
    }
    cout << "Ending. All child processes should have disappeared\n"
            "(Press enter to end this program) ";
    getline(cin, cmd);
    return 0;
}

