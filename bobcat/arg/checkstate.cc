#include "arg.ih"

void Arg::checkState()
{
    switch (d_getOpt)
    {
        case ':':
            throw Errno(0, 
                "ArgData::ArgData(): missing value for option: ") <<
                insertable << d_optErr << throwable;
        // exception thrown

        case '?':
            throw Errno(0, "ArgData::ArgData(): unknown option: ") <<
                    insertable << d_optErr << throwable;
        // exception thrown

        default:
        return;
    }
}
