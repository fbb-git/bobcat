#include "handler.hh"

void Handler::childProcess() 
try
{
    IFdStream in(d_descriptor); // stream to read from client
    OFdStream out(d_descriptor); // stream to write to client

    string cmd;
    
    while (getline(in, cmd))
    {
        cout << "Got: " << cmd << endl;
        out << "Got: " << cmd << "\r" << endl;
    
        if (cmd[0] == 'q')
            throw 1;                 // terminate the server
    }
    throw 0;
}
catch (int ret)
{
    close(d_descriptor);        // the connection is terminated
    cerr << "Child process " << getpid() << " exits with status " << 
                                                            ret << endl;

    exit(ret);
}
