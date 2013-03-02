#include "glob.ih"

void Glob::verify() const
{
    if (int x = d_share->err)
    {
        d_share->err = 0;
        throw Errno(x, "Glob: glob() failed or illegal Flag specified");
    }
}
