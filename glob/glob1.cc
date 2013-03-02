#include "glob.ih"

Glob::Glob(string const &pattern, Flags flags, Dots dots)
:
    d_share(new GlobShare)
{
    d_share->users = 1;

    if (glob(pattern.c_str(), flags, 0, &d_share->globStruct))
        exit(1);

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), 
                         FnWrap1<char const *, bool>(&isDot));
}
    
