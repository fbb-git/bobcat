#include "foldstream.ih"

inline void FoldStream::open(char const *fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    d_fb.pubsync();
    d_fb.setMargins(leftIndent, rightMargin);
    d_fb.setTrailingBlanks(tb);
    d_out.open(fname);
}
