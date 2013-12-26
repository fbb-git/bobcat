#include "process.ih"

Process::~Process()
{
    stop();

//    Signal::instance().add(SIGCHLD, *this);
}

