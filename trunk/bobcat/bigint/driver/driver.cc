#include <iostream>
#include <algorithm>
#include <string>

#include "../bigint"
#include <bobcat/errno>

using namespace std;
using namespace FBB;

void binary(BigInt const &bi)
{
    cout << bi.size() << " bits: ";
    for (size_t idx = bi.sizeInBytes() * 8 ; idx--; )
        cout << bi[idx];
    cout << '\n';
}

int main(int argc, char **argv)
try
{   
    if (argc == 1)
        throw Errno(1, "Provide h (hex), o (oct), or d (dec) argument");

//    BigInt value;
//
//    int mode = argv[1][0];
//
//    cin >>
//        (mode == 'h' ? hex : mode == 'o' ? oct : dec) >>
//        value;
//
//    if (cin.fail())
//        cout << "Input failed\n";
//    else
//        cout << '\n' <<
//                   value << '\n' <<
//            oct << value << '\n' <<
//            hex << value << '\n';

    BigInt zero;        // default construction of a BigInt
    cout << "Defaults to zero: " << zero << '\n';

    BigInt other(zero); // Copycons
    cout << "Copying zero: " << other << '\n';
    
    BigInt five(5);     // Member template
    cout << "Member template constructs 5: " << five << '\n';
    
    cout << "five.operator-(): " << -five << '\n';
    cout << "five.negate(): " << five.negate() << '\n';
    cout << "five.isNegative(): " << five.isNegative() << '\n';

    five.setNegative(false);
    cout << "five.setNegative(false): negative? " << five.isNegative() << 
                                                                        '\n';

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
                                                                        '\n';
    five = 5;
    cout << "five: " << five << ". ";
    binary(five);

    cout << "five[1]: " << five[1] << '\n';

    five[1] |= 1;
    cout << "five[1] |= 1: " << five[1] << '\n';

    cout << "five: " << five << ". ";
    binary(five);

    five[1] ^= 1;
    cout << "five[1] ^= 1: " << five[1] << '\n';
    cout << "five: " << five << ". ";
    binary(five);

    cout << "five[0] &= 1: " << (five[0] &= 1) << '\n';
    cout << "five: " << five << ". ";
    binary(five);

    BigInt large(0x123456);
    cout << hex << "0x" << large << '\n';
    char *bigEndian = large.bigEndian();
    for (size_t idx = 0; idx < large.sizeInBytes(); ++idx)
        cout << "byte[" << idx << "]: 0x" << 
            static_cast<int>(static_cast<unsigned char>(bigEndian[idx])) <<
            '\n';
    swap(bigEndian[0], bigEndian[large.sizeInBytes()-1]);
    
    string newValue(bigEndian, bigEndian + large.sizeInBytes());
    delete[] bigEndian;

    large = BigInt::setBigEndian(newValue);
    cout << "Swapped lowest and highest bytes: 0x" << large << dec << '\n';

    cout << "large = five: " << (large = five) << '\n';

    cout << "large += large: " << (large += large) << '\n';

    cout << "large.addMod(five, 13) : " << large.addMod(five, 13) << '\n';

    large = 123456789;
    
    cout << "large (= 123456789) / 1234 = " << (large /= 1234) << '\n';

    large = 123456789;
    BigInt remainder;
    large.div(&remainder, 1234);
    cout << "Remainder of the division: " << remainder << '\n';

    cout << "GCD of " << large << " and 123 is: " << large.gcd(123) << '\n';

    cout << "large.sqr(): " << large.sqr() << '\n';

    cout << "large.sqrmod(" << "12345): " << large.sqrMod(12345) << '\n';

    cout << "Binary |, & and ^ operations:\n";
    large = 0x123;
    binary(large);
    binary(large | 0x111);
    binary(large ^ 0x111);
    binary(large & 0x111);

    cout << large << " == " << large << "? " << (large == large) << '\n';    
    cout << large << " != " << large << "? " << (large != large) << '\n';    

    cout << large << " < " << five << "? " << (large < five) << '\n';    
    cout << large << " <= " << five << "? " << (large <= five) << '\n';    
    cout << large << " > " << five << "? " << (large > five) << '\n';    
    cout << large << " >= " << five << "? " << (large >= five) << '\n';    

    large = 123456789;
    cout << large << ".exp(4) = ";
    cout << large.expc(4) << '\n';

    cout << large << ".expModc(123, 169) = ";
    cout << large.expModc(123, 169) << '\n';

    BigInt invmod(large.inverseModc(169));
    cout << "large.inverseMod(169) = invmod = " << invmod << '\n';
    cout << large << ".mulModc(invmod, 169): ";
    cout << large.mulModc(invmod, 169) << '\n';

    cout << "as: (large * invmod) % 169: " << (large * invmod) % 169 << '\n';

    cout << "Illustrating encryption using xor operations:\n";
    string orig("This is the secret message");
    cout << "original text:         " << orig << '\n';
    BigInt origNr;
    origNr = BigInt::setBigEndian(orig);
    BigInt randnr(BigInt::rand(origNr.size()));
    
    cout << "orig text in hex:      " << hex << origNr << dec << '\n';
    cout << "same nr of random nrs: " << hex << randnr << dec << '\n';

    cout << hex;
    cout << "orig txt ^ random nrs: " << (origNr ^= randnr) << '\n';
    cout << "orig txt ^ random nrs: " << (origNr ^= randnr) << dec << '\n';

    cout << "retrieved text: ";
    char *txt = origNr.bigEndian();
    cout.write(txt, origNr.sizeInBytes()) << '\n';
}
catch(Errno const &err)
{
    cout << err.what() << '\n';
    return 1;
}


