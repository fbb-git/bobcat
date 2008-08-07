#include "hostname.ih"

void Hostname::init()
{
    if (addressType() != AF_INET)
        throw Errno(0, "Hostname::init(): no AF_INET address type found");
}
