#include "hostname.ih"

Hostname::Hostname(string const &host)
:
    Hostent(GetHostent::gethostent("Hostname::Hostname(std::string)", host))
{
    init();
}
