inline OFdStream::OFdStream(int fd, size_t n)
:
    OFdStreambuf(fd, n),
    std::ostream(this)
{}
