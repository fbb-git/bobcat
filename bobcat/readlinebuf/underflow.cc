#include "readlinebuf.hh"

int ReadLineBuf::underflow()
{
    delete[] d_buffer;
    d_buffer = 0;

    char *beyond = (this->*d_readline)();

    if (beyond == 0)
        return EOF;

    setg(d_buffer, d_buffer, beyond);

            // the static_cast<size_t char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...
    return static_cast<unsigned char>(*gptr());
}
