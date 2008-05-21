#include "cgi.ih"

void CGIFSA::charRange()
{
    size_t end = static_cast<unsigned char>(d_buffer[0]);

    d_stack.pop();                  // hyphen

    size_t begin = static_cast<unsigned char>(d_stack.top());
    d_stack.pop();                  // first char

    if (begin <= end)
        for_each(begin, end + 1, *this, &CGIFSA::setEscape);

    acceptAll();                       // unescape any remaining chars
}


