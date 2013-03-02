/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <bobcat/glob>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

Glob makeGlob(char const *pat)
{
    return Glob(pat, Glob::PERIOD, Glob::DEFAULT);
}

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "Provide glob-expression as 1st arg\n";
        return 1;
    }

    cout << "\nGeneral:\n";

    Glob general;

    for (size_t idx = 0; idx < general.size(); idx++)
        cout << idx << ": " << general[idx] << '\n';

    cout << "\nPattern: " << argv[1] << "\n";

    Glob pattern(makeGlob(argv[1]));
    Glob copy(pattern);
    copy = general;

    for (size_t idx = 0; idx < pattern.size(); idx++)
        cout << idx << ": " << pattern[idx] << '\n';

    cout << "\nThe next glob will fail, this is intended behavior\n";

    Glob fails("*", 1023);

    return 0;
}
catch (Errno const &err)
{
    cout << err.what() << '\n';
    return err.which();
}
