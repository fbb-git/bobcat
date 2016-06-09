#include <bobcat/pipe>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    Pipe p;                         // construct a pipe

    cout << "Read file descriptor: " << p.readFd() << endl;
    cout << "Write file descriptor: " << p.writeFd() << endl;

    int pid = fork();

    if (pid == -1)
        return 1;

    if (!pid)                       //child
    {
        p.readFrom(STDIN_FILENO);   // read what goes into the pipe from cin

        string s;
    
        getline(cin, s);
    
        cout << "CHILD: Got `" << s << "'" << endl;    

        getline(cin, s);
    
        cout << "CHILD: Got `" << s << "'" << endl;    

        return 0;
    }

    p.writtenBy(STDOUT_FILENO);      // write to the pipe via cout

    cout << "first line" << endl;
    cout << "second line" << endl;

    waitpid(pid, 0, 0);
}
catch (exception const &err)
{
    cout << err.what() << endl;
    return 1;
}


