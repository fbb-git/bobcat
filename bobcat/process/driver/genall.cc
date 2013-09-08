#include <iostream>

using namespace std;

// Generate output to cout and cerr, and read cin

int main()
{
    string line;

    size_t count = 0;

    while (getline(cin, line))
    {
        cout << "Got " << line << endl;

        if (count++ % 2 == 0)
            cerr << "Err line " << count << '\n';
    }
}
