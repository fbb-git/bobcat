#include "process.ih"

Process::Process(size_t bufSize, IOMode mode, std::string const &command)
:
    Process(bufSize, mode, NO_PATH, 0, command)
{}
