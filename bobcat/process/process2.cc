#include "process.ih"

Process::Process(size_t mode, std::string const &command)
:
    Process(200, static_cast<IOMode>(mode & ALL_IOMODES), NO_PATH, 0, command)
{}
