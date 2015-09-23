#include "ofoldstreambuf.hh"

int OFoldStreambuf::overflow(int c)
{
    //cerr << c << ' ' << static_cast<char>(c) << endl;

    switch (d_mode)
    {
        case INDENT: 
            indent(c);
        break;

        case WS:
            ws(c);
        break;

        case NON_WS:
            nonWs(c);
        break;
    }

    return c;
}
