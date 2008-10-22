#include "process.ih"

void Process::parentRedirections()
{
    d_selector = Selector();

    int fd;

    if (d_mode & CIN)
    {
        d_childCinbuf.open(fd = d_child_inp->writeOnly());
        d_childCin.rdbuf(&d_childCinbuf);
std::cerr << "USING FD " << fd << endl;
    }

    if (d_mode & (MERGE_COUT_CERR | COUT))
    {
        fd = d_child_outp->readOnly();
        d_childCoutbuf.open(fd);
        d_childCout.rdbuf(&d_childCoutbuf);
        d_selector.addReadFd(fd);
std::cerr << "USING FD " << fd << endl;
    }

//    if ((d_mode & CERR) && !(d_mode & MERGE_COUT_CERR))
//    {
//        fd_e = d_child_errp->readOnly();
//std::cerr << "USING FD " << fd_e << endl;
//
//        d_selector.addReadFd(fd_e);
//        d_childCerrbuf.open(fd_e);
//        d_childCerr.reset(new istream(&d_childCerrbuf));
//    }


    if (d_oldIn != -1)
        ::close(d_oldIn);
    if (d_oldOut != -1)
        ::close(d_oldOut);

    clear();
}





