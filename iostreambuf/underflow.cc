#include "iostreambuf.ih"

int IOStreambuf::underflow()
{
    int c;

    c = d_in->get();

    if (c == EOF)
        setg(&d_buf, &d_buf + 1, &d_buf + 1);
    else
    {
        d_buf = c;
        setg(&d_buf, &d_buf, &d_buf + 1);
    }
    return c;
}
