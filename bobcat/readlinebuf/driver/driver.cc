#include <iostream>
#include <istream>
#include <cstdio>
#include <sstream>
#include <iomanip>

#include <bobcat/readlinebuf>

using namespace std;
using namespace FBB;

int main()
{
    ReadLineBuf readlineBuf(10);
    istream in(&readlineBuf);

    size_t count = 0;
    string line;
    while (true)
    {
        ostringstream prompt;
        prompt << setw(2) << ++count << ": ";
        readlineBuf.setPrompt(prompt.str());

        if (!getline(in, line))          // uses the last-set prompt
            break;

        cout << "Retrieved: " << line << '\n';
    }
}
