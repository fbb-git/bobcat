#include "glob.hh"

Glob::Glob(Type type, string const &pattern, int flags, Dots dots)
try
:
    d_share(new GlobShare {glob_t {}, 1, type} )
{
    if (flags & ~(ERR | MARK | NOSORT | NOESCAPE | PERIOD))
        throw Exception(flags) << "Glob: unknown Flag specified";

    int err = glob(pattern.c_str(), flags, 0, &d_share->globStruct);

    if (err)
        throw Exception(err) << "Glob: glob() failed";

    accept(type);

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), isDot);
}
catch(...)
{
    delete d_share;
    throw;
}
