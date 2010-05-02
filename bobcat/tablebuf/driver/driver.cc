#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <iterator>

#include <bobcat/tablebuf>
#include <bobcat/tablelines>

using namespace std;
using namespace FBB;

int main()
{
    TableLines tablelines;
                        
    tablelines << 0;            // set separator widths
    for (size_t sep = 0; sep != 8; ++sep)
        tablelines << 3;


    TableBuf tab(tablelines, 8, TableBuf::ROWWISE);

    ostream out(&tab);

    copy(istream_iterator<string>(cin), istream_iterator<string>(),
            ostream_iterator<string>(out, "\b"));

    cout << tab << '\n';            // complete the table and insert
}

