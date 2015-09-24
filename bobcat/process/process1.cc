#include "process.ih"

Process::Process(std::string const &command)
:
    Process(ALL, NO_PATH, 0, 200, command)
{}
