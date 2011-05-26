#include <iostream>
#include <string>
#include "../binarysearch"

using namespace std;
using namespace FBB;

string words[] = 
{
    "eight",                // alphabetically sorted number-names
    "five",
    "four",
    "nine",
    "one",
    "seven",
    "six",
    "ten",
    "three",
    "two"
};

class Comparator
{
    public:
        bool operator()(string const &left, string const &right) const;
};

inline bool Comparator::operator()(string const &left, 
                                   string const &right) const
{
    return left < right;
}


bool compFun(string const &left, string const &right)
{
    return left < right;
}


int main()
{
    string *ret = binary_search(words, words + 10, "five");
    if (ret != words + 10)
        cout << "five is at offset " << (ret - words) << endl;

    ret = binary_search(words, words + 10, "grandpa");
    if (ret == words + 10)
        cout << "grandpa is not the name of a number\n";

    ret = binary_search(words, words + 10, "five", Comparator());
    if (ret != words + 10)
        cout << "five is at offset " << (ret - words) << endl;

    ret = binary_search(words, words + 10, "grandpa", compFun); 
                                                   // or use: Comparator()
    if (ret == words + 10)
        cout << "grandpa is not the name of a number\n";

    return 0;
}

