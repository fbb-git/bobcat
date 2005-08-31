#include "serversocket.ih"

SocketBase ServerSocket::accept() throw (Errno)
{
    sockaddr_in address;

    socklen_t   size = sizeof(address);

    int sock =
            ::accept
            (
                socket(),
                reinterpret_cast<sockaddr *>(&address),
                &size
            );
        
    if (sock < 0)
        throw Errno("ServerSocket::accept()");


    class MakeSocketBase: public SocketBase
    {
        public:
            MakeSocketBase(int socket, sockaddr_in const &addr)
            :
                SocketBase(socket, addr)
            {}
    };

    return MakeSocketBase(sock, address);
}



