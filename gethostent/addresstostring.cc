#include "gethostent.ih"

string GetHostent::addressToString(char const *prefix, void const *ads)
{
    char buffer[100];

    if (!prefix || !inet_ntop(AF_INET, ads, buffer, 100))
        throw Errno(prefix);

    return buffer;
}
