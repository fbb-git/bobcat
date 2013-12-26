#include "process.ih"

Process::Process(IOMode mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    Process(200, mode, processType, timeLimit, command)
{}
