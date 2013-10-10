inline sockaddr const *InetAddress::sockaddrPtr() const
{
    return reinterpret_cast<sockaddr const *>(&d_address);
}
