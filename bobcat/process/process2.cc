#include "process.ih"

Process::Process(size_t mode, std::string const &command)
:
    Process(iomode(mode), NO_PATH, 0, 200, command)
{}
