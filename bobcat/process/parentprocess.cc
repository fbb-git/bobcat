#include "process.ih"

#include <iostream>

void Process::parentProcess()
{
    int outFd = d_out->readOnly();
    int errFd = d_err->readOnly();

    std::cout << "STDOUT via " << outFd << ", STDERR via " << errFd << endl;

    Selector selector;
    
    selector.addReadFd(outFd);
    selector.addReadFd(errFd);

    d_cout.clear();                 // clear the standard output line(s)
    d_cerr.clear();                 // clear the standard error line(s)

    while (true)
    {
        try
        {
            selector.wait();
        }
        catch(Errno)
        {
            break;
        }

        int rfd = selector.getReadFd();

        if (rfd == outFd)
            collect(&d_cout, rfd);
        else if (rfd == errFd)
            collect(&d_cerr, rfd);
        else 
            break;
    }

    d_ret = waitForChild();

    close(outFd);
    close(errFd);
}

