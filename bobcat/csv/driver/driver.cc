#include <iostream>

#include "../csv"

using namespace std;
using namespace FBB;

int main()
{
    CSV csv("I5 S2 D3");

    cin >> csv;

    cout << 
        "Size: " << csv.size() << ". "         // number of specified fields
        "Count: " << csv.count() <<            // number of available fields
    '\n';



//        csv.count() <<              // number of available fields
//        csv.get<int>(0) <<          // get value[0] or its default value
//        csv.available<int>(0) <<    // get value[0] or throw an exception
//        csv[3] <<                   // field 3 as a string, possibly empty
//        csv.begin() <<              // bidirectional const iterator returning
//                                    // strings 
//        csv.begin<Type>() <<        // bidirectional const iterator returning
//                                    // Type values 
//        csv.rbegin() <<             // reverse iterator returning strings
//        csv.rbegin<Type>() <<       // reverse iterator returning Type values
//
//    csv.available();                // bool vector indicating which fields are
//                                    // available
//    csv.data();                     // vector<string> const & holding all
//                                    // fields 

}


