inline void OFilterStreambuf::open(std::ostream &out)
{
    close();
    d_out = &out;
}
