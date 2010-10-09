#include "readlinebuf.ih"

int ReadLineBuf::underflow()
{
    delete[] d_buffer;
    d_buffer = 0;

    (this->d_readline)();

    setg(d_buffer, d_buffer, d_buffer + buflen + 1);

            // the static_cast<size_t char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...
    return static_cast<unsigned char>(*gptr());
}
