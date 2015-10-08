#include "readlinebuf.ih"

char *ReadLineBuf::nextLine(char *buf)      // malloc allocated buf
{
    string line(buf);

    if (d_history && not line.empty())      // add line (+ maybe a timestamp) 
    {                                       // to the history 
        add_history(buf);
        if (d_timestamp)
            add_history_time((*d_timestamp)().c_str());
    }

    free(buf);                              // done with the malloc-ed buf.

    d_buffer = new char[line.length() + 1]; // room for the next line + '\n'

                                            // copy buf (+ '\n') to d_buffer
    d_buffer[line.copy(d_buffer, string::npos)] = '\n';

    return d_buffer + line.length() + 1;    // returns 'd_buffer.end()'
}

