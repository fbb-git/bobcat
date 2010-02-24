#include <iostream>
#include <ostream>
#include <cstring>
#include <iomanip>
#include <bobcat/errno>
#include <bobcat/hmacbuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc < 3)
        throw Errno(1, "Arg1: key, arg2: digest method required");

    string key(argv[1]);

    HMacBuf hmacbuf(key, argv[2]);
    ostream out(&hmacbuf);

    string hw("hello world\n");

    out << hw;
    hmacbuf.close();
    cout << ">" << hmacbuf << "<" << endl;

    hmacbuf.open();
    out.write(hw.c_str(), hw.length());
    hmacbuf.close();
    cout << ">" << hmacbuf << "<" << endl;
}
catch(Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}
