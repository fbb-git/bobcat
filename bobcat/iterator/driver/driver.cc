// To compile do:
//                  g++ --std=c++11 driver.cc

#include <algorithm>
#include <iterator>
#include <iostream>

#include "../iterator"

using namespace std;
using namespace FBB;

int main()
{
    copy(Iterator<int>(10), Iterator<int>(20), 
            ostream_iterator<int>(cout, ", "));
    cout << '\n';

    copy(ReverseIterator<int>(20), ReverseIterator<int>(10),
            ostream_iterator<int>(cout, ", "));
    cout << '\n';
}
