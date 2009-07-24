#include "glob.ih"

Glob &Glob::operator=(Glob const &other)
{
    if (this != &other)
    {
        destroy();        
        copy(other);
    }
    return *this;
}
