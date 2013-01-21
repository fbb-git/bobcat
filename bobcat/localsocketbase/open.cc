#include "localsocketbase.ih"

void LocalSocketBase::open(std::string const &name)
{
    d_address.sun_family = AF_UNIX;

    if (name.length() >= sizeof(d_address.sun_path))
        throw Exception() << "LocalSocketBase::open(" << name << ')';

    d_address.sun_path[name.copy(d_address.sun_path, string::npos)] = 0;

    d_length = sizeof(d_address.sun_family) + name.length();
    
    d_socket = ::socket(AF_UNIX, SOCK_STREAM, 0);

    if (d_socket < 0)
        throw Exception() << "LocalSocketBase::open(" << name << ')';
}
