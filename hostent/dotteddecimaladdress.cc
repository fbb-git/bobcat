#include "hostent.hh"

string Hostent::dottedDecimalAddress(size_t nr) const
{
    char buffer[100];
    char const *ba = binaryAddress(nr);

    return (ba && inet_ntop(AF_INET, ba, buffer, 100)) ?
        buffer
    :
        "";
}
