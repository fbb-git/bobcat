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
        throw Errno("1st arg: method, 2nd arg: key, 3rd arg: file to "
                    "encrypt (to stdout), 4rd char (opt): iv");

    string key(argv[2]);
    string iv;

    if (argc > 4)
        iv = argv[4];

    EncryptBuf encryptbuf(cout, argv[1], key, iv);

    ostream out(&encryptbuf);

    ifstream in(argv[3]);

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
