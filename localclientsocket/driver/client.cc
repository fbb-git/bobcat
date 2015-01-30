#include <iostream>
#include <bobcat/localclientsocket>
#include <bobcat/ifdstream>
#include <bobcat/ofdstream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cerr << "Provide filename representing the unix domain socket\n";
        return 1;
    }

    LocalClientSocket client(argv[1]);
    int fd = client.connect();
    string line;

    cout << "Connecting to socket " << fd << endl;

    IFdStream in(fd);                 // stream to read from        
    OFdStream out(fd);                // stream to write to

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
            "Can't connect to " << argv[1] << endl;
    return 1;
}

