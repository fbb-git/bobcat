#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::openStream()
{
    User user;

    if (d_name.empty())
        d_name = user.homedir() + ".primes";
    else if (d_name[0] == '~')
        d_name.replace(0, 1, user.homedir());

    d_stream.open(d_name, ios::in | ios::out);

    if (not d_stream)
    {
        d_stream.clear();
        Exception::open(d_stream, d_name, ios::out | ios::trunc | ios::in);
    }

//    d_stream << hex;
}
