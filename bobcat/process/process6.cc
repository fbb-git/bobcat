#include "process.ih"

Process::Process(size_t bufSize, IOMode mode, ProcessType type, 
                 std::string const &command)
:
    Process(bufSize, mode, type, 0, command)
{}
