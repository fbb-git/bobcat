#include "bigint.ih"

bool BigInt::addDigit(char ch, Context &ctx)
{
    if (not (*ctx.pConv)(static_cast<unsigned char>(ch)))
        return true;        // true means: character outside of expected range
                            // which will end find_if.

    ctx.ret *= ctx.radix;
    ctx.ret += isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;

    return false;
}
