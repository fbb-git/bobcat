#include "hostname.hh"

Hostname::Hostname(string const &host)
:
    Hostent(GetHostent::gethostent("Hostname::Hostname(std::string)", host))
{
    init();
}
