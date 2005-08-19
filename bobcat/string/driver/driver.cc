/*
                              driver.cc
*/

#include "driver.h"
#include "../string.h"

using namespace std;
using namespace FBB;

static char const *type[] = 
{
    "DQUOTE_UNTERMINATED",
    "SQUOTE_UNTERMINATED",
    "ESCAPED_END",
    "SEPARATOR",
    "NORMAL",
    "DQUOTE",
    "SQUOTE",
};

int main(int argc)
{
    if (argc == 1)
        cout << "Provide an argument to suppress SEPARATOR fields\n";

    while (true)
    {
        cout << "Enter a line, or empty line to stop:" << endl;

        String line;
        if (!getline(cin, line) || !line.length())
            break;

        vector<String::SplitPair> splitpair;
        cout << "Split into " << line.split(&splitpair, " \t", argc == 1) << 
                " fields\n"; 
        for 
        (
            vector<String::SplitPair>::iterator it = splitpair.begin();
                it != splitpair.end();
                    ++it
        )
            cout << (it - splitpair.begin() + 1) << ": " <<
                    type[it->second] << ": `" << it->first << 
                    "', unescaped: `" << String(it->first).unescape() << 
                    "'" << endl;
    }
    return 0;
}
