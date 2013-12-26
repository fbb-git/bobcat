#include "process.ih"

Process::Process(IOMode mode, std::string const &command)
:
    Process(200, mode, NO_PATH, 0, command)
{}
