inline void MultiStreambuf::stream::setOnce(stream &os)
{
    if (os.d_mode == RESET)
        os.d_mode = ONCE;
}
