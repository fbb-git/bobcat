#include "handler.ih"

void Handler::childProcess() 
try
{
    IFdStream in(d_descriptor); // stream to read from client
    string cmd;

    if (getline(in, cmd))
    {
        cerr << "Child process gets: `" << cmd << "'" << endl;

        if (cmd[0] != 'q')      // terminate if client sends `q'
            throw 0;
    }
    throw 1;
}
catch (int ret)
{
    close(d_descriptor);        // the connection is terminated
    cerr << "Child process " << getpid() << " exits with status " << 
                                                            ret << endl;

    exit(ret);
}
