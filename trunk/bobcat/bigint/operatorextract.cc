#include "bigint.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, BigInt &bn)
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

    bool validInput = false;
    while (true)
    {
        int ch = static_cast<unsigned char>(in.peek());

        if (not (*charType)(ch))
        {
            if (!validInput)
            {
                in.setstate(ios::failbit);
                return in;
            }
            break;
        }

        in.get();
        value += ch;
        validInput = true;
    }

    bn = BigInt::fromText(value, flags);
    return in;
}

}
