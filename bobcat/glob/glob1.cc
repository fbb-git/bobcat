#include "glob.ih"

Glob::Glob(string const &pattern, int flags, Dots dots)
:
    d_share(new GlobShare, globShareDeleter)
{
    d_share->globErr = flags;

    if (flags & ~(ERR | MARK | NOSORT | NOESCAPE | PERIOD))
        throw Errno(flags, "Glob: unknown Flag specified");

    int err = glob(pattern.c_str(), flags, 0, &d_share->globStruct);
    d_share->globErr = err;

    if (err)
        throw Errno(err, "Glob: glob() failed");

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), 
                         FnWrap1<char const *, bool>(&isDot));
}
