#include "process.ih"

Process::Process(size_t mode, ProcessType type, std::string const &command)
:
    Process(200, static_cast<IOMode>(mode & ALL_IOMODES), type, 0, command)
{}
