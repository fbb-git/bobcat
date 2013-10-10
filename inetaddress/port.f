inline uint16_t InetAddress::port() const
{
    return ntohs(d_address.sin_port);
}
