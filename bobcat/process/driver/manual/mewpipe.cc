#include "main.hh"



Pipe *newPipe()
{
    Pipe *ret = new Pipe;
    ret->verify();
    return ret;
}

