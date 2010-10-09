#include <iostream>
#include <istream>
#include <cstdio>
#include <sstream>
#include <iomanip>

#include <bobcat/readlinestream>

using namespace std;
using namespace FBB;

int main()
{
    ReadLineStream terminal(10);

    size_t count = 0;
    string line;
    while (true)
    {
        ostringstream prompt;
        prompt << setw(2) << ++count << ": ";
        terminal.setPrompt(prompt.str());

        if (!getline(terminal, line))       // uses the last-set prompt
            break;

        cout << "Retrieved: " << line << '\n';
    }
}
