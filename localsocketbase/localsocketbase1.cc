#include "localsocketbase.hh"

LocalSocketBase::LocalSocketBase()
:
    d_length(0),
    d_socket(-1)
{
    memset(&d_address, 0, sizeof(struct sockaddr_un));
}
