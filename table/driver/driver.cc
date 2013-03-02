#include <iostream>

#include <bobcat/table>
#include <bobcat/tablelines>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    TableLines tablelines;
                                // width/separators of cols 0, 1 and 2
    tablelines << 0 << " | " << " | ";

                                // hline over cols 1 and 2 of row 1
    tablelines << TableLines::HLine(1, 1, 3); 

    Table tab(tablelines, 3, Table::ROWWISE, Table::EQUALWIDTH);
    // or: Table tab(tablelines, 3, Table::ROWWISE);
 
    tab << Align(0, std::left);     // set column non-default alignment
    tab.fill(argv + 1, argv + argc);// fill range of values
    cout << tab << '\n';            // complete the table and insert
 
    tab << "hello" << "" << "wo";   // add additional elements.
    if (tab.nRows() > 2)
        tab << Align(2, 2, center); // set the layout of a specific element
 
    cout << tab << '\n';
}
