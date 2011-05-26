#include "ofoldstream.ih"

void OFoldStream::open(ostream &out, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldStreambuf::open(out);
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
