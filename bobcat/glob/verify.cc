#include "glob.ih"

void Glob::verify() const
{
    s_ok = true;
    if (!d_ok)
        throw Errno("Glob: glob() failed or illegal Flag specified");
}
