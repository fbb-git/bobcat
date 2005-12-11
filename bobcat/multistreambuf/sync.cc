#include "multistreambuf.ih"

int MultiStreambuf::sync()
{
    if (!d_buffer.length())
        return 0;

    Insert istruct = {d_buffer, true};

    for_each(d_os.begin(), d_os.end(), 
            Wrap1c<stream, Insert>(&insert, istruct));

    d_buffer.erase();
    return istruct.ok ? 0 : 1;
}

