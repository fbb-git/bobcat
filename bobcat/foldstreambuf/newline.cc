#include "foldstreambuf.ih"

void FoldStreambuf::newline()
{
    //cerr << "NEWLINE\n";

    put('\n');
    d_next = 0;
}
