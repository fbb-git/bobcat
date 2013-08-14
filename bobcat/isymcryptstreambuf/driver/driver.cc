#include "../isymcryptstreambuf"

#include <iostream>

using namespace std;
using namespace FBB;

int main()
{
    ISymCryptStreambuf<ENCRYPT> ebuf(cin, EVP_bf_cbc(), 1000,
                                    "1234567890", "1234567890");
    istream ein(&ebuf);

    ISymCryptStreambuf<DECRYPT> dbuf(ein, EVP_bf_cbc(), 1000,
                                    "1234567890", "1234567890");
    istream din(&dbuf);

    cout << din.rdbuf();
}
