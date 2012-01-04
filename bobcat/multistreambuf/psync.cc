#include "multistreambuf.ih"

int MultiStreambuf::pSync()
{
    if (!d_buffer.length())
        return 0;

    Insert istruct = {d_buffer, true};

    for (auto &os: d_os)
        insertStruct(os, istruct);

    d_buffer.erase();
    return istruct.ok ? 0 : 1;
}

