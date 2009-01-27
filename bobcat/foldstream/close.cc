#include "foldstream.ih"

inline void FoldStream::close()
{
    d_fb.pubsync();
    d_out.close();
}

    
