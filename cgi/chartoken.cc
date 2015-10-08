#include "cgi.ih"

size_t CGIFSA::charToken()
{
    char c;

    if (!d_in.get(c))
        throw END;

    d_buffer = c;

    return static_cast<unsigned char>(c);
}
