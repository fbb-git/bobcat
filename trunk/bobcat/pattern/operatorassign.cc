#include "pattern.ih"

Pattern &Pattern::operator=(Pattern const &other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;    
}
