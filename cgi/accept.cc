#include "cgi.hh"

void CGIFSA::accept()
{
    for (auto iter = d_buffer.rbegin(), end = d_buffer.rend();
        iter != end;
            ++iter)
        d_stack.push(*iter);

    acceptAll();
    d_stack.push(*d_buffer.rbegin());
}
