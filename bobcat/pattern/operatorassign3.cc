#include "pattern.ih"

#include "../iuo/iuo"

Pattern &Pattern::operator=(Pattern const &&tmp)
{
    static bool called = false;
    deprecated__(called, "Pattern::operator=(Pattern const &&tmp) is "
                        "deprecated. Please recompile this program");
     swap(const_cast<Pattern &>(tmp));
    return *this;    
}
