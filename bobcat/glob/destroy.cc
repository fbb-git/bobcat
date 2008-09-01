#include "glob.ih"

void Glob::destroy()
{
    if (!--d_share->users)
    {
        globfree(&d_share->globStruct);
        delete d_share;

        if (!s_ok)
            s_ok = bobcatVerify("Glob");
    }
}
