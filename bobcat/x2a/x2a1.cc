#include "x2a.ih"

X2a::X2a(double x, unsigned behind)
{
    double power = pow(10, static_cast<double>(behind));
    *this << round(x * power) / power;

    string::size_type pos = str().find_first_of('.');
    if (pos == string::npos)
        *this << '.';
    else
        behind -= str().length() - pos - 1;
    fill_n(ostream_iterator<char>(*this), behind, '0');
}
