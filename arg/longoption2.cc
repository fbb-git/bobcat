#include "arg.ih"

LongOption__::LongOption__(char const *name, int optionChar)
:
    d_name(name),
    d_type(AsCharOption),
    d_optionChar(optionChar)
{}
