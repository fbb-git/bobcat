#include <iostream>

#include <bigint>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

void binary(BigInt const &bi)
{
    cout << bi.size() << ": ";
    for (size_t idx = bi.sizeInBytes() * 8 ; idx--; )
        cout << bi[idx];
    cout << endl;
}

int main()
try
{
//    BigInt one((static_cast<int>('a') << 16) + 
//               (static_cast<int>('b') << 8) + 'c');
//
//    binary(one);
//    one = ~one;
//    binary(one);
//    one = ~one;
//    binary(one);

    BigInt five(5);
    binary(five);

    binary(five.tilde());
    cout << five.tilde() << endl;
    cout << (five & five.tilde()) << endl;
    binary(five.tilde().tilde());

    binary(five.tildeInt());
    cout << five.tildeInt() << endl;
    cout << (five & five.tildeInt()) << endl;
    binary(five.tildeInt().tildeInt());

    
//    BigInt five(5 + (7 << 8));
//    binary(five);
//
//    BigInt bi(12);
//    binary(bi);
//
//    BigInt ret = five ^ bi;
//    binary(ret);
//
//    BigInt wip(13);
//
//    BIGNUM *bn = const_cast<BIGNUM *>(&wip.bignum());
//
//    BigInt ptr(bn);
//
//    cout << ptr << endl;

//    BN_set_negative(bn, 0);
//
//    if (wip.compare(BigInt()) < 0)
//        cout << "negative\n";
//
//    size_t size = wip.sizeInBits();
//
//    cout << size << endl;
//
//    if (wip.hasBit(2))
//        cout << "Has Bit 2\n";
//
//    wip *= -1;
//
//    if (wip.compare(BigInt()) < 0)
//        cout << "negative\n";
//
//    size = wip.sizeInBits();
//
//    cout << size << endl;
//
//
//    if (wip.hasBit(2))
//        cout << "Has Bit 2\n";
//
//
//return 0;
//
//    BigInt bv(12346);           // initialized to a value
//
//    BigInt bcopy(bv);           // a copy
//
//    cout << bcopy << " " << hex << bcopy << dec << endl;    // display twice
//    cout << (bcopy += bcopy) << endl;                       // add BigInts
//
//    cout << bv.mulMod(bcopy, BigInt(123))   << endl;
//
//    cout << (bv *= bcopy) << endl;
//
//    cout << BigInt(13) / BigInt(5) << endl;
//
//    BigInt remainder;
//    cout << BigInt(13).div(&remainder, BigInt(5)) << " " << remainder << endl;
//
//    cout << BigInt(75).gcd(BigInt(45)) << endl;
//
//    cout << bcopy.sqrMod(BigInt(123)) << endl;

    return 0;
}
catch(Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}


