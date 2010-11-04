#include <iostream>
#include <bobcat/serversocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

#include <bobcat/a2x>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cerr << "Provide server port number\n";
        return 1;
    }

    size_t portnr = A2x(argv[1]);

    ServerSocket server(portnr);

    cerr << "server listens on port " << argv[1] << endl;

    cerr << "serversocket returns:\n" <<
        "address = " << server.dottedDecimalAddress() << endl <<
        "port    = " << server.port() << endl;

    int fd = server.socket();       // open the socket's descriptor

    cout << "File descriptor of the socket is " << fd << endl <<
        "The server terminates when it receives a single `q' on a line\n"
        "A connection is terminated when no input is received anymore.\n"
        "Then another connection is possible" << endl;

    server.listen();                // listen in blocking mode

    while (true)
    {
        SocketBase fdb = server.accept();
        int fd = fdb.socket();

        cerr << "Client FD = " << fd << ", " << endl <<
                "address = " << fdb.dottedDecimalAddress() << ", " << 
                endl <<
                "communication through port " << fdb.port() << endl;

        IFdStream in(fd);           // stream to read from client
        OFdStream out(fd);          // stream to write to client
        string cmd;
        
        while (getline(in, cmd))
        {
            cout << "Got: " << cmd << endl;
            out << "Got: " << cmd << "\r" << endl;

            if (cmd[0] == 'q')
                return 0;
        }
        cout << "Ready for another connection\n";
    }
}
catch (Errno const &err)
{
    cerr <<
        err.why() << endl <<
        "Server socket on port " << argv[1] << 
        " can't be opened" << endl;
    return -1;
}        

