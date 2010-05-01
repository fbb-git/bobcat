#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include <bobcat/tablebuf>
#include <bobcat/tablelines>

using namespace std;
using namespace FBB;

int main()
{
    TableLines tablelines;
                                // width/separators of cols 0, 1 and 2
    tablelines << 0 << " | " << " | ";

                                // hline over cols 1 and 2 of row 1
    tablelines << TableLines::HLine(
            TableLines::LEFT_MID|TableLines::RIGHT_MID, 1, 1, 2); 

    TableBuf tab(tablelines, 3, TableBuf::ROWWISE, TableBuf::EQUALWIDTH);

    tab << Align(0, std::left);     // set column non-default alignment

    ostream out(&tab);

    out << "one" << fs << fs << "two" << rs <<
            fs << "three";

    cout << tab << '\n';            // complete the table and insert
}

