#include <iostream>
#include <string>
#include <bobcat/ofoldstream>

using namespace std;
using namespace FBB;

void margins(ostream &out)
{
    cout << OFoldStream::leftMargin(out) << ", " << 
            OFoldStream::rightMargin(out) << endl;
}

int main()
{
    OFoldStream out(cout, 4, 40);

    out << lm(4);

    string line;
    while (getline(cin, line))
        out << line << '\n';

    margins(out);

    return 0;
}
