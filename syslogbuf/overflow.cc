#include "syslogbuf.ih"

int Syslogbuf::overflow(int c)
{
    if (c != EOF)
        d_buffer += static_cast<char>(c);
    else
        sync();

    return c;
}
    
