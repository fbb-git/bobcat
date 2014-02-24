#include <iostream>

#include "../csv"

using namespace std;
using namespace FBB;

int main()
{
    CSV csv("I5 S2 D3");

    cin >> csv;

    cout << 
        "Size: " << csv.size() <<       // number of specified fields
        ". "         
        "Count: " << csv.count() <<     // number of available fields
        ". "         
        "Field 2 as int via get: " << csv.get<int>(2) <<
        ". "         
        "Field 2 as int via available: " << csv.available<int>(2) <<
        ". "         
        "Field 6 as string via get: " << csv.get<string>(6) <<
        ". "         
        "Field 6 as string via available: " << csv.available<string>(6) <<
        ". "         
        "Field 3 via operator[]: " << csv[3] <<
    '\n';

//        csv.begin() <<              // bidirectional const iterator returning
//                                    // strings 
//        csv.begin<Type>() <<        // bidirectional const iterator returning
//                                    // Type values 
//        csv.rbegin() <<             // reverse iterator returning strings
//        csv.rbegin<Type>() <<       // reverse iterator returning Type values
//
    csv.available();                // bool vector indicating which fields are
                                    // available
    csv.data();                     // vector<string> const & holding all
                                    // fields 

}


