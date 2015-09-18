#include "localserversocket.hh"

LocalServerSocket::~LocalServerSocket()
{
    if (d_unlink)
        unlink(d_name.c_str());
}
            








