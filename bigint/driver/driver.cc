#include <iostream>
#include <algorithm>
#include <string>

#include "../bigint"
#include <bobcat/exception>

using namespace std;
using namespace FBB;

void binary(BigInt const &bi)
{
    cerr << bi.size() << " bits: ";
    for (size_t idx = bi.sizeInBytes() * 8 ; idx--; )
        cerr << bi[idx];
    cerr << '\n';
}

int main(int argc, char **argv)
try
{   
    if (argc == 1)
        throw Exception(1) << "Provide h (hex), o (oct), or d (dec) argument";

//    BigInt value;
//
//    int mode = argv[1][0];
//
//    cin >>
//        (mode == 'h' ? hex : mode == 'o' ? oct : dec) >>
//        value;
//
//    if (cin.fail())
//        cerr << "Input failed\n";
//    else
//        cerr << '\n' <<
//                   value << '\n' <<
//            oct << value << '\n' <<
//            hex << value << '\n';


    BigInt zero;        // default construction of a BigInt
    cerr << "Defaults to zero: " << zero << '\n';

    BigInt other{zero}; // Copycons

    cerr << "Copying zero: " << other << '\n';

    BigInt five(5);     // Member template
    cerr << "Member template constructs 5: " << five << '\n';

    cerr << "five.operator-(): " << -five << '\n';
    cerr << "five.negate(): " << five.negate() << '\n';
    cerr << "five.isNegative(): " << five.isNegative() << '\n';

    five.setNegative(false);
    cerr << "five.setNegative(false): negative? " << five.isNegative() << 
                                                                        '\n';

    cerr << "five: " << five << ". ";
    binary(five);

    cerr << "five.tildeBits(): " << five.tildeBits() << ". ";
    binary(five);
    five = 5;
    
    cerr << "five.tildeInt(): " << five.tildeInt() << ". ";
    binary(five);
    
    cerr << "++ --zero: " << ++ --zero << " (zero = " << zero << ")\n";
    BigInt zeroOrg(zero--);
    cerr << "zeroOrg(zero--): zeroOrg: " << zeroOrg << ", zero: " << zero <<
                                                                        '\n';
    five = 5;
    cerr << "five: " << five << ". ";
    binary(five);

    cerr << "five[1]: " << five[1] << '\n';

    five[1] |= 1;
    cerr << "five[1] |= 1: " << five[1] << '\n';

    cerr << "five: " << five << ". ";
    binary(five);

    five[1] ^= 1;
    cerr << "five[1] ^= 1: " << five[1] << '\n';
    cerr << "five: " << five << ". ";
    binary(five);

    cerr << "five[0] &= 1: " << (five[0] &= 1) << '\n';
    cerr << "five: " << five << ". ";
    binary(five);

    BigInt large(0x123456);
    cerr << hex << "0x" << large << '\n';
    char *bigEndian = large.bigEndian();
    for (size_t idx = 0; idx < large.sizeInBytes(); ++idx)
        cerr << "byte[" << idx << "]: 0x" << 
            static_cast<int>(static_cast<unsigned char>(bigEndian[idx])) <<
            '\n';
    swap(bigEndian[0], bigEndian[large.sizeInBytes()-1]);
    
    string newValue(bigEndian, bigEndian + large.sizeInBytes());
    delete[] bigEndian;

    large = BigInt::setBigEndian(newValue);
    cerr << "Swapped lowest and highest bytes: 0x" << large << dec << '\n';

    cerr << "large = five: " << (large = five) << '\n';

    cerr << "large += large: " << (large += large) << '\n';

    cerr << "large.addMod(five, 13) : " << large.addMod(five, 13) << '\n';

    large = 123456789;
    
    cerr << "large (= 123456789) / 1234 = " << (large /= 1234) << '\n';

    large = 123456789;
    BigInt remainder;
    large.div(&remainder, 1234);
    cerr << "Remainder of the division: " << remainder << '\n';

    cerr << "GCD of " << large << " and 123 is: " << large.gcd(123) << '\n';

    cerr << "large.sqr(): " << large.sqr() << '\n';

    cerr << "large.sqrmod(" << "12345): " << large.sqrMod(12345) << '\n';

    cerr << "Binary |, & and ^ operations:\n";
    large = 0x123;
    binary(large);
    binary(large | 0x111);
    binary(large ^ 0x111);
    binary(large & 0x111);

    cerr << large << " == " << large << "? " << (large == large) << '\n';    
    cerr << large << " != " << large << "? " << (large != large) << '\n';    

    cerr << large << " < " << five << "? " << (large < five) << '\n';    
    cerr << large << " <= " << five << "? " << (large <= five) << '\n';    
    cerr << large << " > " << five << "? " << (large > five) << '\n';    
    cerr << large << " >= " << five << "? " << (large >= five) << '\n';    

    large = 123456789;
    cerr << large << ".exp(4) = ";
    cerr << large.expc(4) << '\n';

    cerr << large << ".expModc(123, 169) = ";
    cerr << large.expModc(123, 169) << '\n';

    BigInt invmod(large.inverseModc(169));
    cerr << "large.inverseMod(169) = invmod = " << invmod << '\n';
    cerr << large << ".mulModc(invmod, 169): ";
    cerr << large.mulModc(invmod, 169) << '\n';

    cerr << "as: (large * invmod) % 169: " << (large * invmod) % 169 << '\n';

    cerr << "Illustrating encryption using xor operations:\n";
    string orig("This is the secret message");
    cerr << "original text:         " << orig << '\n';
    BigInt origNr;
    origNr = BigInt::setBigEndian(orig);
    BigInt randnr(BigInt::rand(origNr.size()));
    
    cerr << "orig text in hex:      " << hex << origNr << dec << '\n';
    cerr << "same nr of random nrs: " << hex << randnr << dec << '\n';

    cerr << hex;
    cerr << "orig txt ^ random nrs: " << (origNr ^= randnr) << '\n';
    cerr << "orig txt ^ random nrs: " << (origNr ^= randnr) << dec << '\n';

    cerr << "retrieved text: ";
    char *txt = origNr.bigEndian();
    cerr.write(txt, origNr.sizeInBytes()) << '\n';
}
catch(exception const &err)
{
    cerr << err.what() << '\n';
    return 1;
}


