#include "process.hh"

Process::Process(size_t mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    Process(iomode(mode), processType, timeLimit, 200, command)
{}
