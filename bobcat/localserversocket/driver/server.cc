#include <iostream>
#include <bobcat/localserversocket>
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
        cerr << "Provide local filename, e.g., /tmp/uds\n";
        return 1;
    }

    LocalServerSocket server(argv[1]);

    cerr << "server using `" << argv[1] << "'" << endl;

    cout << 
        "The server terminates when it receives a single `q' on a line\n"
        "A connection is terminated when no input is received anymore.\n"
        "Then another connection is possible" << endl;

    server.listen();                // listen in blocking mode

    while (true)
    {
        int fd = server.accept();

        cerr << "Client FD = " << fd << ", " << endl;

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
        err.what() << endl <<
        "Server socket on port " << argv[1] << 
        " can't be opened" << endl;
    return -1;
}        

