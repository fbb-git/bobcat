#include <iostream>
#include <bobcat/iquotedprintablestream>

using namespace std;
using namespace FBB;

int main()
{
    IQuotedPrintableStream<ENCODE> in(cin);

    cout << in.rdbuf();         // quoted printable encode the info on
                                // cin.
}
