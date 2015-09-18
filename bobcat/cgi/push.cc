#include "cgi.hh"

void CGIFSA::push()
{
    for (auto &element: d_buffer)
        d_stack.push(element);
}
