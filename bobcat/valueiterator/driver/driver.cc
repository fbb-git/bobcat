#include <algorithm>
#include <iterator>
#include <iostream>

#include "valueiterator.h"

using namespace std;

int main()
{
//    Reversed<int>::iterator r2( ValueIterator<int>(20) );
//    ValueIterator<int>::reverse r2(ValueIterator<int>(20));
    ValueIterator<int>::reverse r2(20);

//    reverse_iterator<ValueIterator<int>> r10(ValueIterator<int>(10));
//
    copy(ValueIterator<int>::reverse(20), 
        ValueIterator<int>::reverse(10),
        ostream_iterator<int>(cout, ", "));
    cout << '\n';
}
