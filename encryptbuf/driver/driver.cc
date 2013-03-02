#include <iostream>
#include <fstream>
#include <bobcat/errno>
#include <bobcat/encryptbuf>
#include <bobcat/ohexstreambuf>

#include <openssl/evp.h>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Errno("1st arg: method, 2nd arg: key, 3rd arg:  (opt): iv, "
                    "stdin: file to encrypt (to stdout)");

    string key(argv[2]);
    string iv;

    if (argc > 3)
        iv = argv[3];

    EncryptBuf encryptbuf(cout, argv[1], key, iv);
    ostream out(&encryptbuf);

    cerr << "Block length: " << encryptbuf.blockLength() << '\n' <<
            "Key length: " << encryptbuf.keyLength() << '\n' <<
            "Max Key length: " << EVP_MAX_KEY_LENGTH << '\n' <<
            "IV length: " << encryptbuf.ivLength() << endl;
            
    cerr << encryptbuf.iv().length() << ' ';

    OHexStreambuf ohsb(cerr);

    ostream ohs(&ohsb);
    ohs.write(encryptbuf.iv().data(), encryptbuf.iv().length()) << flush;
    cerr << endl;

    out << cin.rdbuf();
}
catch(Errno const &err)
{
    cout << err.why() << endl;
    return 1;
}
