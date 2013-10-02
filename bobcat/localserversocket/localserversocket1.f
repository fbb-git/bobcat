inline LocalServerSocket::LocalServerSocket(std::string const &name, 
                                           Socket action)
{
    open(name, action);
}
