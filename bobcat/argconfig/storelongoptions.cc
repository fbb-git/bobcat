#include "argconfig.ih"

void ArgConfig::storeLongOptions(LongOption const *begin, 
                                 LongOption const *const end)
{
    while (begin != end)
    {
        d_longOption[begin->d_optionChar] = begin->d_name;
        ++begin;
    }
}
