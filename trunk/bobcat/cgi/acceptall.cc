#include "cgi.ih"

void CGIFSA::acceptAll()
{
    while (d_stack.size())
    {
        char top = d_stack.top();
        setEscape(top);
        d_stack.pop();
    }
}
