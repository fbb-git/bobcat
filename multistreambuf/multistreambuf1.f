inline MultiStreambuf::MultiStreambuf(std::ostream &os, Mode mode)
{
    insert(os, mode);
}
