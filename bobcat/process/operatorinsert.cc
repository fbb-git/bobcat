#include "process.ih"

Process &Process::operator<<(std::ostream &(*pf)(std::ostream &))
{
    if (verify())
        dynamic_cast<std::ostream &>(*this) << pf;
    return *this;
}

