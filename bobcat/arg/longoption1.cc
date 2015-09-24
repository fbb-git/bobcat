#include "arg.ih"

LongOption__::LongOption__(char const *name, Type type)
:
    d_name(name),
    d_type(type),
    d_optionChar(0)        
{}
