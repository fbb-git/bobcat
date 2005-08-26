#include "process.ih"

Process &Process::operator+=(std::string const &command)
{
    *this << command;

    return *this;
}
