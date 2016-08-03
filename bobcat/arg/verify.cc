#include "arg.ih"

void Arg__::verify()
{
    switch (d_getOpt)
    {
        case ':':
        throw Exception{1} <<
                "ArgData::ArgData(): missing value for option: " << d_msg;

        case '?':
        throw Exception{1} << "ArgData::ArgData(): unknown option: " << d_msg;

        default:
        return;
    }
}
