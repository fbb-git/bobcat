#include <iostream>

using namespace std;

// Generates output to cout and cerr, and reads cin

int main()
{
    string line;

    size_t count = 0;

    while (getline(cin, line))
    {
        ++count;
        if (count % 5 == 0)
            cerr << "Cerr line " << count << ": " << line << endl;
        else
            cout << "Cout line " << count << ": " << line << endl;
    }
}
