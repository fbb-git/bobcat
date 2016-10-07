#include "gethostent.ih"

void GetHostent::solveName(char const *prefix, string const &host)
{
    struct sockaddr_in addr{AF_INET};

    inet_pton(AF_INET, host.c_str(), &addr.sin_addr);
    s_address = addr.sin_addr;

    char name[NI_MAXHOST];
    if (getnameinfo(
            reinterpret_cast<sockaddr *>(&addr), sizeof(addr), 
                    name, NI_MAXHOST, 0, 0, 0) != 0)
        hostError(prefix);

    s_name = name;
    s_hp.h_name = &s_name.front();

}
