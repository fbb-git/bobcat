/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <bobcat/glob>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "Provide glob-expression as 1st arg\n";
        return 1;
    }

    cout << "General:\n";

    Glob general;

    for (size_t idx = 0; idx < general.size(); idx++)
        cout << idx << ": " << general[idx] << endl;

    cout << "Pattern: " << argv[1] << "\n";

    Glob pattern(argv[1], Glob::PERIOD, Glob::DEFAULT);

    for (size_t idx = 0; idx < pattern.size(); idx++)
        cout << idx << ": " << pattern[idx] << endl;

    return 0;
}
catch (Errno const &err)
{
    cout << err.what() << endl;
    return err.which();
}
