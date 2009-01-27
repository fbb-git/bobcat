#include "foldstreambuf.ih"

void FoldStreambuf::indent(int c)
{
    if (c == '\n')
        newline();
    else if (isspace(c))
    {
        d_ws.assign(d_indent, ' ');
        d_wsLength += d_indent;
        addWs(c);
        d_mode = WS;
    }
    else if (c != EOF)
    {
        d_reqIndent = true;
        addNonWs(c);
        d_mode = NON_WS;
    }
}
