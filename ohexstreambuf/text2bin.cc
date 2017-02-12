#include "ohexstreambuf.ih"

string OHexStreambuf::text2bin(string const &in)
{
    string ret;

    for (size_t idx = 0, end = in.length(); idx != end; idx += 2)
        ret += stoul(in.substr(idx, 2), 0, 16);
//    {
//        A2x ax(in.substr(idx, 2));
//        size_t value;
//        ax >> hex >> value;
//        ret += value;
//    }

    return ret;
}
