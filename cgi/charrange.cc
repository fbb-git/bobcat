#include "cgi.ih"

void CGIFSA::charRange()
{
    size_t end = static_cast<unsigned char>(d_buffer[0]);

    d_stack.pop();                  // hyphen

    size_t begin = static_cast<unsigned char>(d_stack.top());
    d_stack.pop();                  // first char

    if (begin <= end)
    {
        for(++end; begin != end; ++begin)
            setEscape(begin);
    }

    acceptAll();                       // unescape any remaining chars
}


