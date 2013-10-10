inline void Selector::addExceptFd(int fd)
{
    addFd(&d_except, fd);
}
