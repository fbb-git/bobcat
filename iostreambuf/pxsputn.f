inline std::streamsize IOStreambuf::pXsputn(char const *buffer, 
                                           std::streamsize n)
{
    return d_out->write(buffer, n) ? n : 0;
}
