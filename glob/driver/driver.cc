/*
                              driver.cc
*/

#include <iostream>
#include <string>

#include <bobcat/exception>
#include <bobcat/glob>


using namespace std;
using namespace FBB;

Glob makeGlob(char const *pat)
{
    cout << "Using pattern " << pat << '\n';
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

    pattern = Glob(Glob::DIRECTORY, argv[1], Glob::PERIOD, Glob::FIRST);
    cout << "Only directories:\n";
    for (size_t idx = 0; idx < pattern.size(); idx++)
        cout << idx << ": " << pattern[idx] << '\n';

    pattern = Glob(Glob::REGULAR_FILE, argv[1], Glob::PERIOD, Glob::FIRST);
    cout << "regular files:\n";
    for (size_t idx = 0; idx < pattern.size(); idx++)
        cout << idx << ": " << pattern[idx] << '\n';


    cout << "\nThe next glob fails, this is intentional\n";

    Glob fails("*", 1023);
}
catch (exception const &err)
{
    cout << err.what() << '\n';
    return 1;
}

