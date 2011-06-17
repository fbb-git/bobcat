// With g++ 4.3 ext/hash_map is deprecated. The following example shows how to
// use hashes with version >= 4.3:

// FOR NOW, THE OPTION -std=c++0x IS REQUIRED

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Hash
{
    public: 
        size_t operator()(char const *str) const
        {
            size_t ret = 0;

            for (size_t idx = 0; *str; ++idx, ++str)
                ret += idx + *str;
            return ret;
        }
};


int main(int argc, char *const *const argv)
{
    pair<char const *, int> d[] = 
    {
        pair<char const *, int>("aap", 18),
        pair<char const *, int>("noot", 20),
        pair<char const *, int>("wim", 30)
    };

    unordered_map<char const *, int, hash<char const *>> hcp(d, d + 3);

    cout << hcp["noot"] << endl;

    return 0;
}




