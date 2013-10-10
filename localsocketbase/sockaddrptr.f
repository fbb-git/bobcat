inline sockaddr const *LocalSocketBase::sockaddrPtr() const
{
    return reinterpret_cast<sockaddr const *>(&d_address);
}
