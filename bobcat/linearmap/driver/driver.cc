#include <iostream>
#include <string>
#include <iostream>

#include <../linearmap>

using namespace std;
using namespace FBB;

int main()
{
    typedef LinearMap<string, string> LM;

    // constructors:
    LM lm;
    LM lm2 = 
    {
        {"one", "value 1"},
        {"two", "value 2"}
    };
    LM lm3(lm2);
        
    LM lm4(lm3.begin(), lm3.end());
    
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

    lm4 = lm2;
    cout << "lm4's size after assignment: " << lm4.size() << '\n';

    lm4.clear();
    cout << "lm4's size after clear: " << lm4.size() << '\n';
};
