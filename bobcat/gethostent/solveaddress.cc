#include "gethostent.ih"

void GetHostent::solveAddress(char const *prefix, string const &host)
{
    s_name = host;
    s_hp.h_name = &s_name.front();

    struct addrinfo hints{0};
    hints.ai_family = AF_INET;
    // hints.ai_socktype = 0;  //  SOCK_STREAM;

    struct addrinfo *res;
    if (getaddrinfo(host.c_str(), 0, &hints, &res) != 0)
        hostError(prefix);

    s_address = reinterpret_cast<sockaddr_in *>(res->ai_addr)->sin_addr; 

    freeaddrinfo(res);
}
