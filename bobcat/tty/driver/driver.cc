#include <iostream>
#include <string>

#include <bobcat/tty>

using namespace std;
using namespace FBB;

int main()
{
    cout << "Enter some text (not echoed): ";
    string line;
    getline(cin >> Tty(Tty::OFF), line);
    cout << "\n"
            "You entered: `" << line << "'\n";
    
    cout << "Enter some text (echoed): ";
    getline(cin >> Tty(Tty::ON), line);
    cout << "You entered: `" << line << "'\n";
}



