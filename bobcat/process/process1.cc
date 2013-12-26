#include "process.ih"

Process::Process(std::string const &command)
:
    Process(200, CIN | COUT | CERR, NO_PATH, 0, command)
{}
