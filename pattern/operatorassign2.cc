#include "pattern.hh"

Pattern &Pattern::operator=(Pattern &&tmp)
{
    swap(tmp);
    return *this;    
}
