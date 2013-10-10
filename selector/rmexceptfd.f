inline void Selector::rmExceptFd(int fd)
{
    FD_CLR(fd, &d_except);
}
