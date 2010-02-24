#include "pattern.ih"

Pattern &Pattern::operator=(Pattern const &&tmp)
{
    swap(const_cast<Pattern &>(tmp));
    return *this;    
}
