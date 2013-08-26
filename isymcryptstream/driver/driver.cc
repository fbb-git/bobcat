#include "../isymcryptstream"

#include <iostream>

using namespace std;
using namespace FBB;

int main()
{
    ISymCryptStream<ENCRYPT> encryptor(cin, "bf-cbc",
                                    "1234567890", "1234567890");

    ISymCryptStream<DECRYPT> decryptor(encryptor, "bf-cbc",
                                    "1234567890", "1234567890");

    cout << decryptor.rdbuf();
}
