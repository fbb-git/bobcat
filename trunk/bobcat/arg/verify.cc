#include "arg.ih"

void Arg::verify()
{
    switch (d_getOpt)
    {
        case ':':
            throw Errno(1, 
                "ArgData::ArgData(): missing value for option: ") <<
                insertable << d_msg << throwable;
        // exception thrown

        case '?':
            throw Errno(1, "ArgData::ArgData(): unknown option: ") <<
                    insertable << d_msg << throwable;
        // exception thrown

        default:
        return;
    }
}
