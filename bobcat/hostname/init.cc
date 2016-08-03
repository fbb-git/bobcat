#include "hostname.ih"

void Hostname::init()
{
    if (addressType() != AF_INET)
        throw Exception{} << 
                "Hostname::init(): no AF_INET address type found";
}
