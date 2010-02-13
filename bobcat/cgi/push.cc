#include "cgi.ih"

void CGIFSA::push()
{
    for (auto iter = d_buffer.begin(), end = d_buffer.end();
        iter != end;
            ++iter)
        d_stack.push(*iter);
}
