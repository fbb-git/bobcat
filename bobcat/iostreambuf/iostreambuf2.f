inline IOStreambuf::IOStreambuf(std::istream &in, std::ostream &out)
{        
    open(in, out);
}
