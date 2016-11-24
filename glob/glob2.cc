#include "glob.ih"

Glob::Glob(Type type, string const &pattern, int flags, Dots dots)
try
:
    d_share(new GlobShare {glob_t {}, 1, type} )
{
    if (flags & ~Flags::mask)
        throw Exception(flags) << "Glob: unknown Flag specified";

    int err = glob(pattern.c_str(), flags & ~NOMATCH, 0, 
                                                    &d_share->globStruct);

    if (err != 0)
    {
        if (not (err == GLOB_NOMATCH and flags & NOMATCH))
            throw Exception(err) << "Glob: glob() failed";
    }

    accept(type);

    if (dots == FIRST)
        stable_partition(mbegin(), mend(), isDot);
}
catch(...)
{
    delete d_share;
    throw;
}
