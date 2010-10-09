#include "readlinebuf.ih"

void ReadLineBuf::readLine()
{
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

}
