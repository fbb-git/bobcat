#include "foldstream.ih"

void FoldStream::open(ostream &out, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    FoldStreambuf::open(out);
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
