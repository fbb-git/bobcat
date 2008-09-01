#include "process.ih"

Pipe *Process::newPipe() const
{
    Pipe *ret = new Pipe;
    ret->verify();
    return ret;
}
