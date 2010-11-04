#include <iostream>
#include <ostream>
#include <bobcat/errno>
#include <bobcat/digestbuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    DigestBuf digestbuf(argv[1]);
    ostream out(&digestbuf);

    string hw("hello world\n");

    out << hw;
    digestbuf.close();
    cout << ">" << digestbuf << "<" << endl;

    digestbuf.open();
    out.write(hw.c_str(), hw.length());
    digestbuf.close();
    cout << ">" << digestbuf << "<" << endl;
}
catch(Errno const &err)
{
    cout << err.why() << endl;
    return 1;
}
