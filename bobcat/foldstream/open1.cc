#include "foldstream.ih"

void FoldStream::open(char const *fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    FoldStreambuf::open(fname);
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
