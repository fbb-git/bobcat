#include "process.ih"

Process::Process(std::string const &command)
:
    Process(CIN | COUT | CERR, NO_PATH, 0, 200, command)
{}
