#include "glob.ih"

Glob::Glob(string const &pattern, int flags, Dots dots)
:
    d_share(new GlobShare)
{
    d_share->users = 1;

    d_ok = 
        (
            glob(pattern.c_str(), flags, 0, &d_share->globStruct)
            ||
            flags & ~(ERR | MARK | NOSORT | NOESCAPE | PERIOD)
        );

    if (!d_ok)
        return;

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), 
                         FnWrap1<char const *, bool>(&isDot));
}
    
