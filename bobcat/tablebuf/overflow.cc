#include "tablebuf.ih"

int TableBuf::overflow(int ch)
{
    if (ch == d_fs)
    {
        d_tabulated = false;
        d_string.push_back(d_str.str());
        d_str.clear();
        d_str = "";
    }
    else if (ch == d_rs)
    {
    }
    else
        d_str << static_cast<char>(ch);

    return ch;        
}

