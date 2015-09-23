#include "main.hh"

void parentRedirections()
{
    d_childCinbuf.open(p1 = d_child_inp->writeOnly());  
    d_childCin.rdbuf(&d_childCinbuf);

    d_childCoutbuf.open(p2 = d_child_outp->readOnly()); 
    d_childCout.rdbuf(&d_childCoutbuf);

    if (oldIn != -1)
        ::close(oldIn);
    if (oldOut != -1)
        ::close(oldOut);

    io.clear();
}
