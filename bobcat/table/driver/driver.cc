#include <iostream>
#include <algorithm>
#include <iterator>

#include "../table"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    Table<char *> table(2, TableSpec::Horizontal);
    vector<string> vs;
    Table<string> tabe(vs.begin(), vs.end(), 2, TableSpec::Horizontal);


    copy(argv, argv + argc, back_inserter(table));

    table.tabulate();   // note: tabulate fills out the 
                        // table to r x c elements

    cout << table << "\n" 
            "NEXT:\n";
 
    table << "one" << next << 3 << next << "two " << 2 << 
                                        next << tabulate; 

    cout << table << "\n" 
            "NEXT:\n";

    table.append("these are additional elements").tabulate();

    cout << table << endl;

    return 0;
}

