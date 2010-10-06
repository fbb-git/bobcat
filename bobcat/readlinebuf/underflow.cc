#include "readlinebuf.ih"

int ReadLineBuf::underflow()
{
    delete[] d_buffer;
    d_buffer = 0;

    char *buf = readline(d_prompt.c_str());     

    if (buf == 0)
        return EOF;

    size_t buflen = strlen(buf);

    if (d_history && buflen > 0)
        add_history(buf);

    d_buffer = reinterpret_cast<char *>(
                    memcpy(new char[buflen + 1], buf, buflen)
                );

    d_buffer[buflen] = '\n';
    free(buf);

    setg(d_buffer, d_buffer, d_buffer + buflen + 1);

            // the static_cast<size_t char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...
    return static_cast<unsigned char>(*gptr());
}
