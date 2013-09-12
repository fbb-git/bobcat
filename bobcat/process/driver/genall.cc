#include <iostream>

using namespace std;

// Generate output to cout and cerr, and read cin

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Use argument 1 for only cout, 2 for only cerr, 3 for "
                "cout+cerr\n";
        return 0;
    }

    int mode = argv[1][0] - '0';

    string line;

    size_t count = 0;

    while (getline(cin, line))
    {
        if (mode & 1)
            cout << "Got " << line << endl;

        if (mode & 2 && count++ % 2 == 0)
            cerr << "Err line " << count << '\n';
    }
}
