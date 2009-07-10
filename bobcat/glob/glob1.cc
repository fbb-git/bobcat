#include "glob.ih"

Glob::Glob(string const &pattern, int flags, Dots dots)
:
    d_share(new GlobShare, globShareDeleter)
{
    d_share->err = 
        (
            (flags & ~(ERR | MARK | NOSORT | NOESCAPE | PERIOD))
            ||
            glob(pattern.c_str(), flags, 0, &d_share->globStruct)
        );

    if (!d_share->err)
        return;

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), 
                         FnWrap1<char const *, bool>(&isDot));

    if (int x = d_share->err)
    {
        d_share->err = 0;
        throw Errno(x, "Glob: glob() failed or illegal Flag specified");
    }
}
