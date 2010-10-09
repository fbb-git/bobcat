#include <iostream>
#include <istream>
#include <cstdio>
#include <sstream>
#include <iomanip>

#include <bobcat/readlinestream>
#include <readline/history.h>

using namespace std;
using namespace FBB;

int main()
{
    ReadLineStream terminal("", ReadLineStream::EXPAND_HISTORY);

    size_t count = 0;
    string line;
    while (true)
    {
        ostringstream prompt;
        prompt << setw(2) << ++count << ": ";
        terminal.setPrompt(prompt.str());

        if (!getline(terminal, line))       // uses the last-set prompt
            break;

        char linech[line.length() + 1];
        linech[line.copy(linech, string::npos)] = 0;
        char *output = 0;
        int result = history_expand(linech, &output);

        cout << (line == linech) << '\n';

        cout << "Retrieved: " << line << '\n';
        cout << "History expansion: " << result << ": " << 
            (result > 0 ? output : "<none>") << '\n';

        cout << "Output = " << reinterpret_cast<void *>(output) << '\n';
        free(output);       // ???

    }
}
