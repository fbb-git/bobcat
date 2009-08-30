#include <iostream>
#include <fstream>
#include <bobcat/errno>
#include <bobcat/encryptbuf>
#include <bobcat/ohexstreambuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Errno("1st arg: key, 2st arg: file to encrypt (to stdout), "
                    "3rd char (opt): iv");

    string key(argv[1]);
    string iv;

    if (argc > 3)
        iv = argv[3];

    EncryptBuf encryptbuf(cout, "aes-128-cbc", key, iv);

    ostream out(&encryptbuf);

    ifstream in(argv[2]);

    OHexStreambuf ohsb(cerr);
    ostream ohs(&ohsb);

    cerr << "Block length: " << encryptbuf.blockLength() << '\n' <<
            "Key length: " << encryptbuf.keyLength() << '\n' <<
            "IV length: " << encryptbuf.ivLength() << endl;
            
    cerr << encryptbuf.iv().length() << ' ';
    ohs.write(encryptbuf.iv().data(), encryptbuf.iv().length()) << flush;
    cerr << endl;

    out << in.rdbuf();
}
catch(Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}
