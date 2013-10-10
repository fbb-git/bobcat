inline IOStream::IOStream()
:
    std::istream(this),
    std::ostream(this)
{}
