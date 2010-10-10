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
    ReadLineStream in("", 10, ReadLineBuf::EXPAND_HISTORY);

    size_t count = 0;
    string line;
    while (true)
    {
        ostringstream prompt;
        prompt << setw(2) << ++count << ": ";
        in.setPrompt(prompt.str());

        if (!getline(in, line))          // uses the last-set prompt
            break;

        cout << "Retrieved: " << line << "\n"
                "Expansion status: ";

        switch (in.expansion())
        {
            case ReadLineBuf::ERROR:
                cout << "ERROR: " << in.expansionError() << '\n';
            break;

            case ReadLineBuf::NO_EXPANSION:
                cout << "no expansion performed\n";
            break;

            case ReadLineBuf::DONT_EXEC:
                cout << "don't execute the expanded line\n";
            break;

            case ReadLineBuf::EXPANDED:
                cout << "expansion successfully performed\n";
            break;
        }
    }
}
