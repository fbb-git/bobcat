inline SocketBase::SocketBase(int socket, sockaddr_in const &address)
:
    InetAddress(address),
    d_sock(socket)
{}
