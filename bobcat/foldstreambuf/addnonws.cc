#include "foldstreambuf.ih"

void FoldStreambuf::addNonWs(int c)
{
    d_nonWs += c;
}
