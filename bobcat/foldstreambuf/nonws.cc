#include "foldstreambuf.ih"

void FoldStreambuf::nonWs(int c)
{
    if (c == '\n')
    {
        flush();
        newline();
        d_mode = INDENT;
    }
    else if (isspace(c))
    {
        flush();
        addWs(c);
        d_mode = WS;
    }
    else if (c != EOF)
        addNonWs(c);
}
