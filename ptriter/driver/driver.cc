#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <iostream>

#include <bobcat/ptriter>

using namespace std;
using namespace FBB;

int main()
{
    cout << "Enter lines, the first word will be the map's key; "
                                            "^D when done.\n";

    string key;
    string line;                    
    unordered_map<string, string> map;
    while (cin >> key && getline(cin, line))    // fill the map
        map[key] = line;
    cout << '\n';

                                        // initialize a support
    vector<decltype(&*map.begin())>     // vector, using ptrIter
        support(ptrIter(map.begin()), ptrIter(map.end()));

                                        // sort 'support'
    typedef unordered_map<string, string>::value_type VT;
    sort(support.begin(), support.end(), 
        [&](VT const *p1, VT const *p2)
        {
            return strcasecmp(p1->first.c_str(), p2->first.c_str()) < 0;
        }
    );

    for(auto &element: support)         // display sorted by key
        cout << element->first << ' ' << element->second << '\n';
}






