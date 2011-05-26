#include "arg.ih"

void Arg::verify()
{
    switch (d_getOpt)
    {
        case ':':
            throw Errno(1, 
                "ArgData::ArgData(): missing value for option: ") << d_msg;
        // exception thrown

        case '?':
            throw Errno(1, "ArgData::ArgData(): unknown option: ") << d_msg;
        // exception thrown

        default:
        return;
    }
}
