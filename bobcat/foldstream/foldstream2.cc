#include "foldstream.ih"

inline FoldStream::FoldStream(char const *fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
:
    std::ostream(0),
    d_out(fname),
    d_fb(d_out, leftIndent, rightMargin, tb)
{
    rdbuf(&d_fb);
}

