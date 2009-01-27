#include "foldstreambuf.ih"

void FoldStreambuf::indent()
{
    for (size_t nr = 0; nr < d_indent; ++nr)
        put(' ');
}
