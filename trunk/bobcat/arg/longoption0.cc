#include "arg.ih"

Arg::LongOption::LongOption(char const *name)
:
    d_name(name),
    d_type(None),
    d_optionChar(0)        
{}
