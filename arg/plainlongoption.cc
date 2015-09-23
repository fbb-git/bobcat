#include "arg.hh"

bool Arg__::plainLongOption(Arg__::LongOption const &longOption)
{
    addLongOption(longOption.d_name);

    if (!longOption.d_optionChar)           // it's a plain long option.
        return true;

    d_getOpt = longOption.d_optionChar;
    return false;                           // not a plain long option:
                                            // it's also a simple option.
}
