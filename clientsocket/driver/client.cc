#include <iostream>
#include <bobcat/clientsocket>
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
        cerr << "Provide servername and port number\n";
        return 1;
    }

    size_t     port = A2x(argv[2]);
    ClientSocket client(argv[1], port);
    int fd = client.connect();
    string line;

    unsigned long addr = 
        const_cast<ClientSocket const &>(client).sockaddr_inPtr()->
                                                            sin_addr.s_addr;

    cout << "Connecting to socket " << fd << endl <<
            "address = " << client.dottedDecimalAddress() << ", (" << 
                                                                 addr << ")\n"
            "communication through port " << client.port() << endl;

    IFdStream in(fd);                 // stream to read from        
    OFdStream out(fd);                // stream to write to

    unsigned long sPort;
    in >> sPort;
    in.ignore(100, '\n');             // get the port used by the server
    sPort ^= addr;

    cout << "Server uses port " << sPort << '\n';

    while (true)
    {
                                // Ask for a textline, stop if empty / none
        cout << "? ";                   
        if (!getline(cin, line) || line.length() == 0)
            return 0;
        cout << "Line read: " << line << endl;
                                // Return the line to the server
        out << line.c_str() << endl;    
        cout << "wrote line\n";

                                // Wait for a reply from the server
        getline(in, line);
        cout << "Answer: " << line << endl;
    }
    return 0;
}
catch (exception const &err)
{
    cerr << err.what() << "\n" <<
            "Can't connect to " << argv[1] << ", port " << argv[2] << endl;
    return 1;
}

