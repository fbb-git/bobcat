#include "primefactors.ih"

PrimeFactors::Factors const &PrimeFactors::factorize(BigInt const &value)
{
    d_factors.clear();
    d_value = value;
    d_last = d_value.isqrtc();
    d_sentinel = d_last + 1;

    availablePrimes();

    if (not d_value.isOne())
        addPrimes();

    return d_factors;
}





