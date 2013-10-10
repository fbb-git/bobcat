inline void Selector::addWriteFd(int fd)
{
    addFd(&d_write, fd);
}
