#include "process.hh"

Process::Process(size_t mode, ProcessType type, std::string const &command)
:
    Process(iomode(mode), type, 0, 200, command)
{}
