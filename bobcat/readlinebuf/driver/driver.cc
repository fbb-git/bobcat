#include <iostream>
#include <istream>
#include <cstdio>

#include "../readlinebuf"

using namespace std;
using namespace FBB;

int main()
{
    ReadLineBuf readlineBuf("? ", 10);

    istream in(&readlineBuf);

    string line;
    while (true)
    {
        int ch1;
        cout << "Char1: " << static_cast<char>(ch1 = in.get()) << "\n";

        if (ch1 == 'q' || ch1 == EOF)
            break;

        cout << "Char2: " << static_cast<char>(in.get()) << '\n';

        if (getline(in, line))
            cout << "Rest: " << line << endl;
    }
}
