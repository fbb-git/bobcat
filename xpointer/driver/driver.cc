#include <iostream>
#include "../xpointer"
#include <bobcat/exception>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc != 3)
    {
        cout << "Two arguments required: x and y pixel-pointerlocation" <<
                endl;
        return 0;
    }

    Xpointer xpointer;

    if (!xpointer.set(stol(argv[1]), stol(argv[2])))
        throw Exception() << "Pointer setting failed";

    int x;
    int y;

    if (!xpointer.get(&x, &y))
        throw Exception() << "Pointer getting failed";

    cout << "Pointer now at " << x << ", " << y << endl;
}
catch (exception const &err)
{
    cout << err.what() << endl;
    return 1;
}

