#include <vector>
#include <iostream>

#include <bobcat/ranger>

using namespace std;
using namespace FBB;

int main()
{
    vector<int> iv {1, 2, 3, 4, 5};
                                    // display and modify a subrange
    for(auto &el: ranger(iv.rbegin() + 1, iv.rend() - 1))
        cout << el++ << ' ';
    cout << '\n';
                                    // display a reversed range
    for(auto &el: ranger(iv.rbegin() + 1, iv.rend() - 1))
        cout << el << ' ';
    cout << '\n';
                                    // same: display using a count
    for(auto &el: ranger(iv.rbegin() + 1, 3))
        cout << el << ' ';
    cout << '\n';

    int intArray[] = {1, 2, 3, 4, 5};  
                                    // display and modify elements 
                                    // in a pointer-based range
    for(auto &el: ranger(intArray + 1, intArray + 3))
        cout << el++ << ' ';
    cout << '\n';
                                    // data now modified
    for(auto &el: ranger(intArray + 1, intArray + 3))
        cout << el << ' ';
    cout << '\n';
                                    // using a count rather than an
                                    // end-pointer
    for(auto &el: ranger(intArray + 1, 3))
        cout << el << ' ';
    cout << '\n';

    int const constInts[] = {1, 2, 3, 4, 5};

                                    // data can't be modified
    for(auto &el: ranger(constInts + 1, constInts + 3))
        cout << el << ' ';
    cout << '\n';
}

