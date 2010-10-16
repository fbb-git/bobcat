#include "multistreambuf.ih"

int MultiStreambuf::pSync()
{
    if (!d_buffer.length())
        return 0;

    Insert istruct = {d_buffer, true};

    for_each(d_os.begin(), d_os.end(), FnWrap::unary(insertStruct, istruct));

    d_buffer.erase();
    return istruct.ok ? 0 : 1;
}

