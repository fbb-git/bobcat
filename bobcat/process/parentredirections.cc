#include "process.ih"

void Process::parentRedirections()
{
    d_selector = Selector();

    int fd;


    if (d_mode & CIN)
    {
        d_childCinbuf.open(fd = d_child_inp->writeOnly());
        d_childCin.rdbuf(&d_childCinbuf);
//std::cerr << "USING in FD " << fd << endl;
    }

    if (d_mode & (COUT | MERGE_COUT_CERR))
    {
        fd = d_child_outp->readOnly();
        d_childCoutbuf.open(fd);
        d_childCout.rdbuf(&d_childCoutbuf);
        d_selector.addReadFd(fd);
//std::cerr << "USING out FD " << fd << endl;
    }

    if (d_mode & CERR)
    {
        fd = d_child_errp->readOnly();
        d_childCerrbuf.open(fd);
        d_childCerr.rdbuf(&d_childCerrbuf);
        d_selector.addReadFd(fd);
//std::cerr << "USING err FD " << fd << endl;
    }

    close(d_oldIn);
    close(d_oldOut);
    close(d_oldErr);

    clear();
}





