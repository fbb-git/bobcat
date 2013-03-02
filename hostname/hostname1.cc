#include "hostname.ih"

Hostname::Hostname(string const &host) throw(Errno)
:
    Hostent(GetHostent::gethostent("Hostname::Hostname(std::string)", host))
{
    init();
}
