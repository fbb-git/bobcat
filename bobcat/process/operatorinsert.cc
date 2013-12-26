#include "process.ih"

Process &Process::operator<<(std::ostream &(*pf)(std::ostream &))
{
    if (active())
    {

        if (pf != FBB::eoi)
            static_cast<std::ostream &>(*this) << pf;
        else
        {        
            close();
            waitForChild();
        }
    }

    return *this;
}

