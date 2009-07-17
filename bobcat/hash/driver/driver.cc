#include "../hash"

#include <iostream>

using namespace FBB;
using namespace std;

int main(int argc, char **argv)
{
    HashStringCase<string> hsc;

    hsc["AAP"] = "noot";
    hsc["Aap"] = "mies";

    cout << hsc["aap"] << endl;

    HashString<string> hs;

    hs["AAP"] = "noot";
    hs["Aap"] = "mies";

    cout << hs["AAP"] << endl;

    HashCharPtr<int> hcp;

    hcp["jan"] = 31;
    hcp["feb"] = 28;

    cout << hcp["jan"] << endl;

}
