#include "readlinebuf.ih"

char *ReadLineBuf::nextLine(char *buf)
{
    size_t buflen = strlen(buf);

    if (d_history && buflen > 0)
    {
        add_history(buf);
        if (d_timestamp)
            add_history_time((*d_timestamp)().c_str());
    }

    d_buffer = reinterpret_cast<char *>(
                    memcpy(new char[buflen + 1], buf, buflen)
                );

    d_buffer[buflen] = '\n';
    free(buf);

    return d_buffer + buflen + 1;
}
