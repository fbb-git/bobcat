#include "cgi.ih"

void CGIFSA::push()
{
    for_each(d_buffer.begin(), d_buffer.end(), d_stack, &stack<char>::push);
}
