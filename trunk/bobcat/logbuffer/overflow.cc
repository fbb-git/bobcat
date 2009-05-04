#include "logbuffer.ih"

int LogBuffer::overflow(int c)
{
    if (!d_active)          // ignore the char if we're not active.
        return c;

    if (c == 0)             // newline without timestamp request
        d_empty = false;

    if (d_insertTimestamp)  // timestamps requested
    {
        if (d_empty)        // write one if there's nothing on the line
        {
            insertTimestamp();
            d_empty = false;
        }
    }
    switch (c)
    {
        case 0:             // write newline, without considering d_empty true
            c = '\n';       // also see logbuffer/operatorinsert.cc
        break;

        case '\n':          // at '\n', set d_empty to true. This generates 
                            // a timestamp at the next insertion
            d_empty = true;
        break;
    }

    return 
        d_stream->write(reinterpret_cast<char const *>(&c), sizeof(char)) ?
            c
        :
            EOF;
}
