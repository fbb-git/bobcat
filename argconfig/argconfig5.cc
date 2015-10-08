#include "argconfig.ih"

ArgConfig__::ArgConfig__(LongOption__ const *begin, 
                         LongOption__ const *const end)
{
    while (begin != end)
    {
        d_longOption[begin->optionChar()] = begin->getName();
        ++begin;
    }
}
