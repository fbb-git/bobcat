inline void Selector::rmWriteFd(int fd)
{
    FD_CLR(fd, &d_write);
}
