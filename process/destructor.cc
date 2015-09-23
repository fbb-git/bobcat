#include "process.hh"

Process::~Process()
{
    stop();

    delete d_data;      // delete additional data
}

