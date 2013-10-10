inline IOStream::IOStream(std::istream &in, std::ostream &out)
:
    std::istream(this),
    std::ostream(this)
{
    open(in, out);
}
