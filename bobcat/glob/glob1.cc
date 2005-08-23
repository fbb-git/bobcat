#include "glob.ih"

Glob::Glob(string const &pattern, Flags flags, Dots dots)
:
    d_share(new GlobShare)
{
    d_share->users = 1;

    if (glob(pattern.c_str(), GLOB_PERIOD, 0, &d_share->globStruct))
        exit(1);

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), 
                         Wrap1<char, bool>(&Glob::isDot));
}
    
