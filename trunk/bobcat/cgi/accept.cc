#include "cgi.ih"

void CGIFSA::accept()
{
    for_each(d_buffer.rbegin() + 1, d_buffer.rend(), 
            d_stack, &stack<char>::push);

    acceptAll();

    d_stack.push(*d_buffer.rbegin());
}
