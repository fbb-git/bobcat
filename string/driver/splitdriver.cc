// compile with 
//  gx splitdriver.cc -L ../tmp/ -lstring -lbobcat

#include <iostream>
#include "../string"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    while (true)
    {
        cout << "? ";
    
        string line;
        if (not getline(cin, line))
            break;

        vector<String::SplitPair> vect(String::split(line, " \t", argc == 1));

        for (auto const &element: vect)
            cout << '`' << element.first << "': " << element.second << '\n';
    }
}




