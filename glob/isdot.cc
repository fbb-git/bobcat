#include "glob.hh"

namespace
{
    string const dot(".");
    string const dot2("..");
}
        
bool Glob::isDot(char const *cp)
{
    return dot == cp || dot2 == cp;
}

