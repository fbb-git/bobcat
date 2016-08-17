/*
                              server.cc
*/

#include <iostream>

#include <bobcat/a2x>
#include <bobcat/serversocket>
#include <bobcat/errno>
#include <bobcat/ifdstream>


using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "port number required\n";
        return 1;
    }        

    size_t portnr = A2x(argv[1]);
    ServerSocket server(portnr);

    server.listen();                        // plain blocking listen-mode

    while (true)
    {
        SocketBase fdb = server.accept();   // wait for incoming
        int fd = fdb.socket();
        
        cerr << "Client FD = " << fd << ", " << endl <<
                "address = " << fdb.dottedDecimalAddress() << ", " <<
                endl <<
                "communication through port " << fdb.port() << endl;
        
        IFdStream in(fd);           // stream to read from client
        string cmd;
        
        if (getline(in, cmd))
        {
            cout << "Got: " << cmd << endl;

            if (cmd[0] == 'q')      // terminate if client sends `q'
                return 0;

            close(fd);              // the connection is terminated
        }
    }  

}
catch(exception const &error)
{
    cerr << error.what() << endl;
    return 1;
}
