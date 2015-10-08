#include "ofoldstream.ih"

void OFoldStream::open(char const *fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldStreambuf::open(fname);
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
