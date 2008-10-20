#include "process.ih"

void Process::close(auto_ptr<Pipe> &pipe, int (Pipe::*fdFun)() const)
{
    if (pipe.get())
        ::close((pipe.get()->*fdFun)());
}
