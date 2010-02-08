#include "cgi.ih"

void CGIFSA::accept()
{
    for_each(d_buffer.rbegin() + 1, d_buffer.rend(), 
            d_stack, 

#if __GNUC__ > 4 && __GNUC_MINOR__ >= 4
#then
// With g++4-4 (?)
        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));
#else
        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
#endif

    acceptAll();

    d_stack.push(*d_buffer.rbegin());
}
