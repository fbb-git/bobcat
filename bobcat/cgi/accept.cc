#include "cgi.ih"

void CGIFSA::accept()
{
    for_each(d_buffer.rbegin() + 1, d_buffer.rend(), 
            d_stack, 
        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));

// With g++4-4 (?)
//        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));

    acceptAll();

    d_stack.push(*d_buffer.rbegin());
}
