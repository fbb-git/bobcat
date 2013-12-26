#include "process.ih"

Process::~Process()
{
    stop();

    delete d_data;      // delete additional data

//    Signal::instance().add(SIGCHLD, *this);
}

