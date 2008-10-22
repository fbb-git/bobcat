#include "process.ih"

// This function performs the steps taken by setPipes and parentRedirections
// to close the child's cin and to keep the defintions of d_oldIn and
// d_child_inp intact.

void Process::close()
{
    d_oldIn = d_child_inp->writeFd();   
    d_child_inp.reset(newPipe());
    d_childCinbuf.open(d_child_inp->writeOnly());

    //    d_childCin.rdbuf(&d_childCinbuf);     not required as d_childCin
    //                                          won't be used anymore in this
    //                                          run. At parentRedirecions
    //                                          it may eventually be
    //                                          reassigned again.

    close(d_oldIn);
}
