#include "localserversocket.ih"

LocalServerSocket::~LocalServerSocket()
{
    if (d_unlink)
        unlink(d_name.c_str());
}
            








