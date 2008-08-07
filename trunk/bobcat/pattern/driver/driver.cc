/*
                              driver.cc
*/

#include "driver.h"

#include <bobcat/pattern>

using namespace std;
using namespace FBB;


void showSubstr(string const &str)
{
    static int 
        count = 1;

    cout << "String " << count++ << " is '" << str << "'\n";
}


int main(int argc, char **argv)
{
    {
        Pattern one("one");
        Pattern two(one);
        Pattern three("a");
        Pattern four;
        three = two;
    }

    try 
    {
        Pattern pattern("aap|noot|mies");

        {
            Pattern extra(Pattern(pattern));
        }
    
        if (pattern << "noot")
            cout << "noot matches\n";
        else
            cout << ": noot doesn't match\n";
    }
    catch (Errno const &e)
    {
        cout << e.what() << ": compilation failed" << endl;
    }
        
    string pat = "\\d+";

    while (true)
    {
        cout << "Pattern: '" << pat << "'\n";

        try
        {
            Pattern patt(pat, argc == 1);   // case sensitive by default,
                                            // any arg for case insensitive

            cout << "Compiled pattern: " << patt.pattern() << endl;

            Pattern pattern;
            pattern = patt;                 // assignment operator

            while (true)
            {
                cout << "string to match : ";

                string st;
                getline(cin, st);
                if (st == "")
                    break;
                cout << "String: '" << st << "'\n";
                try
                {
                    pattern.match(st);

                    Pattern p3(pattern);
        
                    cout << "before:  " << p3.before() << "\n"
                            "matched: " << p3.matched() << "\n"  
                            "beyond:  " << pattern.beyond() << "\n"  
                            "end() = " << pattern.end() << endl;
        
                    for (size_t idx = 0; idx < pattern.end(); ++idx)
                    {
                        string str = pattern[idx];
            
                        if (str == "")
                            cout << "part " << idx << " not present\n";
                        else
                        {
                            Pattern::Position pos = pattern.position(idx);
        
                            cout << "part " << idx << ": '" << str << "' (" <<
                                    pos.first << "-" << pos.second << ")\n";
                        }
                    }
                }
                catch (Errno const &e)
                {
                    cout << e.what() << ": " << st << " doesn't match" << endl;
                    continue;
                }
            }
        }            
        catch (Errno const &e)
        {
            cout << e.what() << ": compilation failed" << endl;
        }

        cout << "New pattern: ";

        if (!getline(cin, pat) || !pat.length())
            return 0;
    }
}





