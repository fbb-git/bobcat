#include "primefactors.ih"

void PrimeFactors::iniRead()
{
    d_stream.clear();
    d_stream.seekg(0);
    d_atSentinel = false;

    nextLoad();
}
