#include "foldstreambuf.ih"

void FoldStreambuf::ws(int c)
{
    if (c == '\n')
    {
        newline();
        clearWs();
        d_mode = INDENT;
    }
    else if (isspace(c))
        addWs(c);
    else if (c != EOF)
    {
        addNonWs(c);
        d_mode = NON_WS;
    }
}
