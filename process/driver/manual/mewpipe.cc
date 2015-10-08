#include "main.ih"



Pipe *newPipe()
{
    Pipe *ret = new Pipe;
    ret->verify();
    return ret;
}

