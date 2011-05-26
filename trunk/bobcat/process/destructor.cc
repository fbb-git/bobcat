#include "process.ih"

Process::~Process()
{
    stop();
}

