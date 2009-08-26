#include <iostream>
#include <algorithm>
#include <string>

#include <bigint>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

void binary(BigInt const &bi)
{
    cout << bi.size() << " bits: ";
    for (size_t idx = bi.sizeInBytes() * 8 ; idx--; )
        cout << bi[idx];
    cout << endl;
}

int main()
try
{   
    BigInt zero;        // default construction of a BigInt
    cout << "Defaults to zero: " << zero << endl;

    BigInt other(zero); // Copycons
    cout << "Copying zero: " << other << endl;
    
    BigInt five(5);     // Member template
    cout << "Member template constructs 5: " << five << endl;
    
    cout << "five.operator-(): " << -five << endl;
    cout << "five.negate(): " << five.negate() << endl;
    cout << "five.isNegative(): " << five.isNegative() << endl;

    five.setNegative(false);
    cout << "five.setNegative(false): negative? " << five.isNegative() << 
                                                                        endl;

    cout << "five: " << five << ". ";
    binary(five);

    cout << "five.tildeBits(): " << five.tildeBits() << ". ";
    binary(five);
    five = 5;
    
    cout << "five.tildeInt(): " << five.tildeInt() << ". ";
    binary(five);
    
    cout << "++ --zero: " << ++ --zero << " (zero = " << zero << ")\n";
    BigInt zeroOrg(zero--);
    cout << "zeroOrg(zero--): zeroOrg: " << zeroOrg << ", zero: " << zero <<
                                                                        endl;
    five = 5;
    cout << "five: " << five << ". ";
    binary(five);

    cout << "five[1]: " << five[1] << endl;

    five[1] |= 1;
    cout << "five[1] |= 1: " << five[1] << endl;

    cout << "five: " << five << ". ";
    binary(five);

    five[1] ^= 1;
    cout << "five[1] ^= 1: " << five[1] << endl;
    cout << "five: " << five << ". ";
    binary(five);

    cout << "five[0] &= 1: " << (five[0] &= 1) << endl;
    cout << "five: " << five << ". ";
    binary(five);

    BigInt large(0x123456);
    cout << hex << "0x" << large << endl;
    char *bigEndian = large.bigEndian();
    for (size_t idx = 0; idx < large.sizeInBytes(); ++idx)
        cout << "byte[" << idx << "]: 0x" << 
            static_cast<int>(static_cast<unsigned char>(bigEndian[idx])) <<
            endl;
    swap(bigEndian[0], bigEndian[large.sizeInBytes()-1]);
    
    string newValue(bigEndian, bigEndian + large.sizeInBytes());
    delete[] bigEndian;

    large.setBigEndian(newValue);
    cout << "Swapped lowest and highest bytes: 0x" << large << dec << endl;

    cout << "large = five: " << (large = five) << endl;

    cout << "large += large: " << (large += large) << endl;

    cout << "large.addMod(five, 13) : " << large.addMod(five, 13) << endl;

    large = 123456789;
    
    cout << "large (= 123456789) / 1234 = " << (large /= 1234) << endl;

    large = 123456789;
    BigInt remainder;
    large.div(&remainder, 1234);
    cout << "Remainder of the division: " << remainder << endl;

    cout << "GCD of " << large << " and 123 is: " << gcd(large, 123) << endl;

    cout << "large.sqr(): " << large.sqr() << endl;

    cout << "large.sqrmod(" << "12345): " << large.sqrMod(12345) << endl;

    cout << "Binary |, & and ^ operations:\n";
    large = 0x123;
    binary(large);
    binary(large | 0x111);
    binary(large ^ 0x111);
    binary(large & 0x111);

    cout << large << " == " << large << "? " << (large == large) << endl;    
    cout << large << " != " << large << "? " << (large != large) << endl;    

    cout << large << " < " << five << "? " << (large < five) << endl;    
    cout << large << " <= " << five << "? " << (large <= five) << endl;    
    cout << large << " > " << five << "? " << (large > five) << endl;    
    cout << large << " >= " << five << "? " << (large >= five) << endl;    

    large = 123456789;
    cout << large << ".exp(4) = ";
    cout << large.exp(4) << endl;

    large = 123456789;
    cout << large << ".expMod(123, 169) = ";
    cout << large.expMod(123, 169) << endl;

    large = 123456789;
    BigInt invmod(inverseMod(large, 169));
    cout << "inverseMod(large, 169) = invmod = " << invmod << endl;
    cout << large << ".mulMod(invmod, 169): ";
    cout << large.mulMod(invmod, 169) << endl;

    large = 123456789;
    cout << "as: (large * invmod) % 169: " << (large * invmod) % 169 << endl;

    cout << "Illustrating encryption using xor operations:\n";
    string orig("This is the secret message");
    cout << "original text:         " << orig << endl;
    BigInt origNr;
    origNr.setBigEndian(orig);
    BigInt randnr(BigInt::rand(origNr.size()));
    
    cout << "orig text in hex:      " << hex << origNr << dec << endl;
    cout << "same nr of random nrs: " << hex << randnr << dec << endl;

    cout << hex;
    cout << "orig txt ^ random nrs: " << (origNr ^= randnr) << endl;
    cout << "orig txt ^ random nrs: " << (origNr ^= randnr) << dec << endl;

    cout << "retrieved text: ";
    char *txt = origNr.bigEndian();
    cout.write(txt, origNr.sizeInBytes()) << endl;

}
catch(Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}


