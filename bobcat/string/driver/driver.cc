#include <iostream>
#include <vector>
#include <bobcat/string>

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

int main(int argc, char **argv)
{
    cout << "Program's name in uppercase: " << String::uc(argv[0]) << "\n\n";

    vector<String::SplitPair> splitpair;
    string text{ "one, two, 'thr\\x65\\145'" };
    string encoded{ String::urlEncode(text) };

    cout << "The string `" << text << "'\n"
            "   as url-encoded string: `" << encoded << "'\n"
            "   and the latter string url-decoded: " << 
                                    String::urlDecode(encoded) << "\n"
            "\n"               
            "Splitting `" << text << "' into " << 
                    String::split(&splitpair, text, String::STRSEP, ", ") << 
                " fields\n"; 

    for (auto it = splitpair.begin(); it != splitpair.end(); ++it)
        cout << (it - splitpair.begin() + 1) << ": " <<
                type[it->second] << ": `" << it->first << 
                "', unescaped: `" << String::unescape(it->first) << 
                "'\n";

    cout << '\n' <<
        text << ":\n"
        "   upper case: " << String::uc(text) << ",\n"
        "   lower case: " << String::lc(text) << '\n';
}

/*
    Calling the program as 
        driver'
    results in the following output:
        Program's name in uppercase: DRIVER
        
        Splitting `one, two, 'thr\x65\145'' into 9 fields
        1: NORMAL: `one', unescaped: `one'
        2: SEPARATOR: `,', unescaped: `,'
        3: NORMAL: `', unescaped: `'
        4: SEPARATOR: ` ', unescaped: ` '
        5: NORMAL: `two', unescaped: `two'
        6: SEPARATOR: `,', unescaped: `,'
        7: NORMAL: `', unescaped: `'
        8: SEPARATOR: ` ', unescaped: ` '
        9: SQUOTE: `thr\x65\145', unescaped: `three'
        
        one, two, 'thr\x65\145':
           upper case: ONE, TWO, 'THR\X65\145',
           lower case: one, two, 'thr\x65\145'

*/





