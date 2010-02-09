#include "cgi.ih"

void CGIFSA::push()
{
    for_each(d_buffer.begin(), d_buffer.end(), d_stack, 
        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));
}
