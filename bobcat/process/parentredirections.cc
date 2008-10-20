#include "process.ih"

void Process::parentRedirections()
{
    d_selector = Selector();

    if (d_mode & CIN)
        d_childCinbuf.open(d_child_inp->writeOnly());

    if (d_mode & (MERGE_COUT_CERR | COUT))
    {
        int fd = d_child_outp->readOnly();
        d_selector.addReadFd(fd);
        d_childCoutbuf.open(fd);

        if (d_fdOut != -1)
            ::close(d_fdOut);
        d_fdOut = fd;
    }

    if ((d_mode & CERR) && !(d_mode & MERGE_COUT_CERR))
    {
        int fd = d_child_errp->readOnly();
        d_selector.addReadFd(fd);
        d_childCerrbuf.open(fd);

        if (d_fdErr != -1)
            ::close(d_fdErr);
        d_fdErr = fd;
    }

    d_childCout.clear();
    d_childCerr.clear();
    d_childCin.clear();

    clear();                        // clear the IO stream

    open(d_childCout, d_childCin);  // associate in/out streams
}

