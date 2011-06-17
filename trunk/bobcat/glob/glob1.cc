#include "glob.ih"

Glob::Glob(string const &pattern, int flags, Dots dots)
try
:
    d_share(new GlobShare)
{
    d_share->users = 1;

    if (flags & ~(ERR | MARK | NOSORT | NOESCAPE | PERIOD))
        throw Errno(flags, "Glob: unknown Flag specified");

    int err = glob(pattern.c_str(), flags, 0, &d_share->globStruct);

    if (err)
        throw Errno(err, "Glob: glob() failed");

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), isDot);
}
catch(...)
{
    delete d_share;
    throw;
}
