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
    
        cerr << "Here we are\n";

        try
        {
            pattern.match("noot");
            cout << "noot matches\n";
        }
        catch (Errno const &e)
        {
            cout << e.what() << ": noot doesn't match" << endl;
        }
    }
    catch (Errno const &e)
    {
        cout << e.what() << ": compilation failed" << endl;
    }
        
/*
    gewenst patroon: 
        \\
    aanbieden aan de de patroon-vertaler:
        \\\\
    dus in de string constante:
        \\\\\\\\

    gewenst:
        \d
    aanbieden aan de patroon vertaler:
        \d
    in de string constante:
        \\d
*/

    string
        pat = "(\\\\\\\\)*(\\\\\\$|\\$(\\d)+)";

    while (true)
    {
        cout << "Patroon: '" << pat << "'\n";

        try
        {
            Pattern 
                patt(pat, argv[1] != 0);
            Pattern 
                pattern;

            pattern = patt;

            pattern.setPattern(pat, argv[1] != 0);
    
            while (true)
            {
                string
                    st;
                cerr << "string to match : " << flush;
                getline(cin, st);
        
                if (st == "")
                    break;
    
                cout << "String: '" << st << "'\n";
    
                try
                {
                    pattern.match(st);

                    Pattern p3(pattern);
        
                    cerr << "before:  " << p3.before() << endl;
                    cerr << "matched: " << p3.matched() << endl;
                    cerr << "beyond:  " << pattern.beyond() << endl;
                    cerr << "end() = " << pattern.end() << endl;
        
                    for (size_t idx = 0; idx < pattern.end(); ++idx)
                    {
                        string
                            str = pattern[idx];
            
                        if (str == "")
                            cerr << "part " << idx << " not present\n";
                        else
                        {
                            Pattern::Position
                                pos = pattern.position(idx);
        
                            cerr << "part " << idx << ": '" << str << "' (" <<
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

        cout << "New pattern: " << flush;

        if (!getline(cin, pat) || !pat.length())
            return 0;
    }
}





