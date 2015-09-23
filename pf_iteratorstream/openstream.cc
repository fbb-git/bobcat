#include "../primefactors/primefactors.hh"

void PrimeFactors::iteratorStream::openStream()
{
    User user;

    if (d_name.find("~/") == 0)
        d_name.replace(0, 2, user.homedir());

    d_stream.open(d_name, ios::in | ios::out);

    if (not d_stream)
    {
        d_stream.clear();
        Exception::open(d_stream, d_name, ios::out | ios::trunc | ios::in);
    }
}
