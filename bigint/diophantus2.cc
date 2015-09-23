#include "bigint.hh"

BigInt BigInt::diophantus(BigInt *factor1, BigInt *factor2, 
                          BigInt const &value1, BigInt const &value2)
{
    BigInt modulo = value1 % value2;

    if (not modulo.isZero())
    {
        BigInt nestedFactor1;
        BigInt gcd = diophantus(&nestedFactor1, factor2, value2, modulo);
        *factor1 = *factor2;
        *factor2 = nestedFactor1 - (value1 / value2) * *factor2;
        return gcd;
    }
    *factor1 = 0;
    *factor2 = 1;
    return value2;
}
