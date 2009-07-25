#include <iostream>

#include <bobcat/bigint>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

int main()
try
{
    BigInt bi;                  // zero-value

    BigInt bv(12346);           // initialized to a value

    BigInt bcopy(bv);           // a copy
    bcopy.verify();

    cout << bcopy << " " << hex << bcopy << dec << endl;    // display twice
    cout << (bcopy += bcopy) << endl;                       // add BigInts

    cout << bv.mulMod(bcopy, 123)   << endl;

    cout << (bv *= bcopy) << endl;

    cout << BigInt(13) / 5 << endl;

    BigInt remainder;
    cout << BigInt(13).div(&remainder, 5) << " " << remainder << endl;

    cout << BigInt(75).gcd(45) << endl;

    cout << bcopy.sqrMod(123) << endl;

    return 0;
}
catch(Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}


