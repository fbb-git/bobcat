inline void Selector::rmReadFd(int fd)
{
    FD_CLR(fd, &d_read);
}
