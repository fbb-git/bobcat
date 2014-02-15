#include <iostream>
#include "../linearmap"

#include <iostream>
#include <string>
#include <iostream>

using namespace std;
using namespace FBB;

//CODE
int main()
{
    typedef LinearMap<string, string> LM;

    // constructors:
    LM lm;
    LM lm2(lm);
    LM lm3 = 
    {
        {"one", "value 1"},
        {"two", "value 2"}
    };
        
    LM lm4(lm.begin(), lm.end());
    
    // assignment:
    lm = lm2;

    // some members:
    lm["key"] = "value";
    cout << lm["key"] << '\n';
    cout << lm.find("key")->second << '\n';

    for (auto value: lm)
        cout << "For loop: " << value.first << ", " << 
                                                value.second << '\n';

    cerr << "# times 'key' is stored: " << lm.count("key") << "\n"
            "# times 'value is stored: " << lm.count("value") << '\n';

    lm4 = lm;

    lm4.clear();
    cout << "lm4's size = " << lm4.size() << '\n';
};
//=











