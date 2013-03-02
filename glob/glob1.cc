#include "glob.ih"

Glob::Glob(string const &pattern, int flags, Dots dots)
:
    Glob(ANY, pattern, flags, dots)
{}
