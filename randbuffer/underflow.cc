#include "randbuffer.hh"

int Randbuffer::underflow()
{
    ostringstream ostr;

    ostr << d_min + 
            static_cast<int>((d_max - d_min) * 
                                (random() / (RAND_MAX + 1.0))) << 
            " ";        

    size_t n = ostr.str().length();

    char *cp = new char[n];
    d_buffer.reset(cp);

    ostr.str().copy(cp, string::npos);
    setg(cp, cp, cp + n);

    return *gptr();
}
