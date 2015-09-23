#include "process.hh"

Process::Process(std::string const &command)
:
    Process(ALL, NO_PATH, 0, 200, command)
{}
