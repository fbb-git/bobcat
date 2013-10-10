inline void Selector::addReadFd(int fd)
{
    addFd(&d_read, fd);
}
