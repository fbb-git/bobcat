inline sockaddr *InetAddress::sockaddrPtr() 
{
    return reinterpret_cast<sockaddr *>(&d_address);
}
