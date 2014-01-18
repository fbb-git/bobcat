#include <iostream>
#include "../linearmap"

#include <iostream>
#include <string>
#include <iostream>

using namespace std;
using namespace FBB;

int main()
{
    typedef LinearMap<string, string> LM;

    // constructors:
    LM lm;
    LM lm2(lm);
    LM lm3(LM());
    LM lm4(lm.begin(), lm.end());

    // assignment:
    lm = lm2;
    lm = LM(lm.begin(), lm.end());

    lm["aap"] = "noot";
    cout << lm["aap"] << '\n';
    cout << lm.find("aap")->second << '\n';

    for (auto value: lm)
        cout << "For: " << value.first << ", " << value.second << '\n';

    cerr << "# times 'aap' is stored: " << lm.count("aap") << "\n";
cerr <<            "# times 'noot is stored: " << lm.count("noot") << '\n';

    lm4 = lm;

    lm4.clear();
    cout << "lm4's size = " << lm4.size() << '\n';

};











