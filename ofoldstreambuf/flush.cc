#include "ofoldstreambuf.hh"

void OFoldStreambuf::flush()
{
    if (d_reqIndent)
    {
        d_reqIndent = false;
        indent();
        writeNonWs();
        d_next = d_indent + d_nonWs.length();
    }
    else if (length() <=  d_rightMargin)
    {
        writeWs();
        writeNonWs();
        d_next += d_wsLength + d_nonWs.length();
    }
    else
    {
        newline();
        indent();
        writeNonWs();
        d_next = d_indent + d_nonWs.length();
    }

//    cerr << "FLUSHNONWS " << d_next << ' ' << d_wsLength << ' ' << 
//                            d_nonWs.length() << ": " << length() << endl;

    d_nonWs.erase();
    clearWs();
}

