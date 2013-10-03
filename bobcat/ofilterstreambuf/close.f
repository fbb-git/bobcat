inline void OFilterStreambuf::close()
{
    sync();
    d_dest.close();
}
