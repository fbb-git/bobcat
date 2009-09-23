#include "bigint.ih"

namespace FBB
{

istream &operator>>(istream &in, BigInt &bn)
{
    string value;

    int flags = in.flags();

    int (*charType)(int) =
            flags & ios::dec ? ::isdigit  : 
            flags & ios::hex ? ::isxdigit :
                            FBB::isoctdigit;

    char c;
    in >> c;        // skip ws
    in.putback(c);

    if (in.peek() == '-')
    {
        in.ignore(1);
        value = '-';
    }

    while (true)
    {
        int ch = static_cast<unsigned char>(in.peek());
        if (not (*charType)(ch))
            break;

        in.ignore(1);
        value += ch;
    }

    bn = BigInt::fromText(value);
    return in;
}

}
