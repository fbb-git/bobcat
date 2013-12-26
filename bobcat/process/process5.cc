#include "process.ih"

Process::Process(IOMode mode, ProcessType type, std::string const &command)
:
    Process(200, mode, type, 0, command)
{}
