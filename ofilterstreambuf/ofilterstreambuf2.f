inline OFilterStreambuf::OFilterStreambuf(char const *fname, openmode mode)
:
    d_dest(fname, mode),
    d_out(&d_dest)
{}
