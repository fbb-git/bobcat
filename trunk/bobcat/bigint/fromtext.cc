#include "bigint.ih"

// conversion stops at the first character outside of the expected range of
// characters. 

BigInt const BigInt::fromText(string const &text, int mode)
{
    BigInt ret;

    if (not mode & (ios::hex | ios::oct | ios::dec))
        mode =
            text.find_first_of("abcdefABCDEF") != string::npos ? ios::hex :
            text.find_first_of("89") == string::npos && 
                                               text[0] == '0'  ? ios::oct :
                                                                 ios::dec;
    BigInt radix(mode & ios::oct ?  8 : 
                 mode & ios::hex ? 16 : 10);

    bool negative = text[0] == '-';
    
    auto iter = find_if(text.begin() + negative, text.end(), 
                        FnWrap::unary(addDigit, ret, radix, 
                                        mode & ios::oct ?   isoctdigit : 
                                        mode & ios::hex ? ::isxdigit   :
                                                          ::isdigit));

    if (iter - text.begin() <= negative)
        throw Errno("fromText: text does not represent a BigInt value");

    if (negative)
        ret.negate();

    return ret;
}









