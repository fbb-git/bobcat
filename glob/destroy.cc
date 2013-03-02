#include "glob.ih"

void Glob::destroy()
{
    if (!d_share)           // for the move-operations
        return;

    if (!--d_share->users)
    {
        globfree(&d_share->globStruct);
        delete d_share;
    }
}
