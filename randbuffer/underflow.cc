#include "randbuffer.ih"

int Randbuffer::underflow()
{
    if (gptr() < egptr())
        return *gptr();

    ostringstream ostr;

    ostr << d_min + 
            static_cast<int>((d_max - d_min) * rand() / (RAND_MAX + 1.0)) << 
            " ";        

    size_t n = ostr.str().length();

    char *cp = new char[n];
    d_buffer.reset(cp);

    ostr.str().copy(cp, string::npos);
    setg(cp, cp, cp + n);

    return *gptr();
}
