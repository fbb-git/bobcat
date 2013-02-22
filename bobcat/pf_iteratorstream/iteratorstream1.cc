#include "../primefactors/primefactors.ih"

PrimeFactors::iteratorStream::iteratorStream(std::string const &name, 
                                              size_t blockSize)
:
    d_name(name),
    d_blockSize(blockSize)
{
    User user;

    if (d_name.empty())
        d_name = user.homedir() + ".primes";
    else if (d_name[0] == '~')
        d_name.replace(0, 1, user.homedir());

    d_stream.open(name, ios::in | ios::out);

    if (not d_stream)
    {
        d_stream.clear();
        Exception::open(d_stream, name, ios::out | ios::trunc | ios::in);
        d_stream.seekp(0);
        d_stream << 2 << '\n' << 3 << endl;
    }

    d_primes.reserve(blockSize);

    iniRead();
}
