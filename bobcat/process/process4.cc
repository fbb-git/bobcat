#include "process.ih"

Process::Process(size_t mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    Process(200, static_cast<IOMode>(mode & ALL_IOMODES), processType, 
            timeLimit, command)
{}
