#include <iostream>

#include "../../foldstream/foldstream"
//#include "../foldstreambuf"

using namespace std;
using namespace FBB;

int main()
{
//    FoldStreambuf fb(cout, 4, 40);
//    FoldStreambuf fb("fsb.out", 4, 40);
//    ostream out(&fb);

    FoldStream out("foldstream.nam2", 4, 40);

//    int c;
//    int linenr = 0;
//    while ((c = cin.get()) != EOF)
//    {
//        if (c == '\n')
//        {
//            if (++linenr == 5)
//                out << indent(+4);
//        }
//        out << static_cast<char>(c);
//    }

    string line;
    out << lmargin(+4);

    while (getline(cin, line))
        out << line << '\n';

    return 0;
}
