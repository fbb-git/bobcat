inline IOStreambuf::pos_type IOStreambuf::pSeekpos(pos_type offset, 
                         std::ios::openmode mode)
{
    return seekoff(offset, std::ios::beg, mode);
}
