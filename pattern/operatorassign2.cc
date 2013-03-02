#include "pattern.ih"

Pattern &Pattern::operator=(Pattern &&tmp)
{
    swap(tmp);
    return *this;    
}
