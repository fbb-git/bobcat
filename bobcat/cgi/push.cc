#include "cgi.ih"

void CGIFSA::push()
{
    for_each(d_buffer.begin(), d_buffer.end(), d_stack, 
#if __GNUC__ > 4 && __GNUC_MINOR__ >= 4
#then
        static_cast<void (stack<char>::*)(char &&)>(&stack<char>::push));
#else
        static_cast<void (stack<char>::*)(char const &)>(&stack<char>::push));
#endif
}
