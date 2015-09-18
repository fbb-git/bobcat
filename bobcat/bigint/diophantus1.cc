#include "bigint.hh"

long long BigInt::diophantus(long long *factor1, long long *factor2, 
                             long long const &value1, long long const &value2)
{
    if (long long modulo = value1 % value2)
    {
        long long nestedFactor1;
        long long gcd = diophantus(&nestedFactor1, factor2, value2, modulo);
        *factor1 = *factor2;
        *factor2 = nestedFactor1 - (value1 / value2) * *factor2;
        return gcd;
    }
    *factor1 = 0;
    *factor2 = 1;
    return value2;
}
