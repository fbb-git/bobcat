#include "tablebuf.hh"

int TableBuf::overflow(int ch)
{
    if (ch == d_fs)
        nextField();
    else if (ch == d_rs)
    {
        nextField();
        endRow();
    }
    else
    {
        d_str += static_cast<char>(ch);
        d_buffered = true;
        d_insertEmptyRow = false;
    }

    return ch;        
}

