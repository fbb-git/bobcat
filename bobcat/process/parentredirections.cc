#include "process.ih"

void Process::parentRedirections()
{
    d_selector = Selector();

    int fd_i = -1;
    int fd_o = -1;
    int fd_e = -1;

    if (d_mode & CIN)
    {
        d_childCinbuf.open(fd_i = d_child_inp->writeOnly());
//std::cerr << "USING FD " << fd_i << endl;
    }

    if (d_mode & (MERGE_COUT_CERR | COUT))
    {
        fd_o = d_child_outp->readOnly();
//std::cerr << "USING FD " << fd_o << endl;

        d_selector.addReadFd(fd_o);
        d_childCoutbuf.open(fd_o);
    }

    if ((d_mode & CERR) && !(d_mode & MERGE_COUT_CERR))
    {
        fd_e = d_child_errp->readOnly();
//std::cerr << "USING FD " << fd_e << endl;
        d_selector.addReadFd(fd_e);
        d_childCerrbuf.open(fd_e);
    }


        if (d_fdErr != -1)
{
//    std::cerr << "CLOSING " << d_fdErr << endl;
            if (::close(d_fdErr))
                ;   //std::cerr << "CANT CLOSE " << d_fdErr << endl;
}
        d_fdErr = fd_e;


        if (d_fdOut != -1)
{
//    std::cerr << "CLOSING " << d_fdOut << endl;
            if (::close(d_fdOut))
                ;   // std::cerr << "CANT CLOSE " << d_fdOut << endl;
}
        d_fdOut = fd_o;


        if (d_fdIn != -1)
{
//    std::cerr << "CLOSING " << d_fdIn << endl;
            if (::close(d_fdIn))
                ;   //std::cerr << "CANT CLOSE " << d_fdIn << endl;
}
        d_fdErr = fd_i;

}





