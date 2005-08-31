#include "hostent.ih"

string Hostent::dottedDecimalAddress(unsigned nr) const
{
    char buffer[100];
    char const *ba = binaryAddress(nr);

    return (ba && inet_ntop(AF_INET, ba, buffer, 100)) ?
        buffer
    :
        "";
}
