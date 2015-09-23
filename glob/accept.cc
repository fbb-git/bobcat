#include "glob.hh"

void Glob::accept(Type type)
{
    auto begin = d_share->begin = new char *[d_share->globStruct.gl_pathc];
    auto dest = begin;

    for 
    (
        auto src = d_share->globStruct.gl_pathv, 
                                    end = src + d_share->globStruct.gl_pathc;
            src != end;
                ++src
    )
    {
        if (Stat(*src).type() & type)
            *dest++ = *src;             // copy the pointer if type is OK
    }

    d_share->size = dest - begin;       // compute the # of accepted entries
    d_share->end = dest;                // end points beyond the last one
}
