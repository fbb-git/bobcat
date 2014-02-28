#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

#include <bobcat/iterator>

using namespace std;
using namespace FBB;

int main()
{
    copy(Iterator<int>(10), Iterator<int>(20), 
            ostream_iterator<int>(cout, ", "));
    cout << '\n';

    copy(Iterator<char>(*Iterator<char>::max() - 9), 
            Iterator<char>::last(*Iterator<char>::max()), 
            ostream_iterator<int>(cout, ", "));
    cout << '\n';

    cout << *Iterator<int>::max() << '\n';
    copy(Iterator<int>(*Iterator<int>::max() - 9), 
            Iterator<int>::last(*Iterator<int>::max()), 
            ostream_iterator<int>(cout, ", "));
    cout << '\n';

    copy(ReverseIterator<int>(20), ReverseIterator<int>(10),
            ostream_iterator<int>(cout, ", "));
    cout << '\n';

    std::string letters(Iterator<char>('a'), Iterator<char>::last('z'));
    cout << letters << '\n';

    std::string caps(ReverseIterator<char>::last('Z'), 
                     ReverseIterator<char>('A'));
    cout << caps << '\n';

}
