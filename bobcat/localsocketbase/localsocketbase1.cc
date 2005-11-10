#include "localsocketbase.ih"

LocalSocketBase::LocalSocketBase(std::string const &name) throw (Errno)
{
    d_address.sun_family = PF_LOCAL;

    if (name.length() >= sizeof(d_address.sun_path))
        throw Errno("LocalSocketBase::LocalSocketBase(name)");

    d_address.sun_path[name.copy(d_address.sun_path, string::npos)] = 0;

    d_length = sizeof(d_address.sun_family) + name.length();
    
    d_socket = ::socket(PF_LOCAL, SOCK_STREAM, 0);

    if (d_socket < 0)
        throw Errno("LocalSocketBase::LocalSocketBase(name)");
}
