/*
                              forkserver2.cc
*/

#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <bobcat/a2x>
#include <bobcat/serversocket>
#include <bobcat/errno>

#include "handler/handler.h"

using namespace std;
using namespace FBB;

void sigchld_handler(int signum)
{
    static bool stop = false;

    int status;
    int pid = waitpid(WAIT_ANY, &status, WNOHANG);

    if (pid <= 0)       // ignore erroroneus or no child available but
    {
        cerr << "waitpid() returned " << pid << ", ignoring\n";
        return;          // the handler is still called.
    }

    stop = (WEXITSTATUS(status) != 0);

    cerr << "Process " << pid << " returns exit status " << 
            WEXITSTATUS(status) << ", stop = " << stop << endl;

    if (stop)                           // terminate when done
        exit(0);                            
}


int main(int argc, char **argv, char **envp)
try
{
    if (argc == 1)
    {
        cout << "port number required\n";
        return 1;
    }        

    signal(SIGCHLD, sigchld_handler);       // handle terminating children

    size_t portnr = A2x(argv[1]);
    ServerSocket server(portnr);

    server.listen();                        // plain blocking listen-mode

    while (true)
    {
        cerr << "\n"
                "Wait for incoming requests..." << endl;

        SocketBase fdb = server.accept();   // wait for incoming
        int fd = fdb.socket();
        
        cerr << "Client FD = " << fd << ", " << endl <<
                "address = " << fdb.dottedDecimalAddress() << ", " <<
                endl <<
                "communication through port " << fdb.port() << endl;
        
        Handler handler(fd);        // create separate process for each
        handler.fork();             // connection
    }  

}
catch(Errno const &error)
{
    cerr << error.what() << endl;
    return 1;
}
