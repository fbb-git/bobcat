#include "glob.ih"

void Glob::destroy()
{
    verify();       // in case no verify was explicitly called

    if (!--d_share->users)
    {
        globfree(&d_share->globStruct);
        delete d_share;
    }
}
