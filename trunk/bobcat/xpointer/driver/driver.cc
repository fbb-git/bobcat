#include <iostream>
#include "../xpointer"
#include <bobcat/errno>
#include <bobcat/a2x>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc != 3)
    {
        cout << "Two arguments required: x and y pixel-pointerlocation" <<
                endl;
        return 1;
    }

    Xpointer xpointer;

    if (!xpointer.set(A2x(argv[1]), A2x(argv[2])))
        throw Errno() << insertable << "Pointer setting failed" << throwable;

    int x;
    int y;

    if (!xpointer.get(&x, &y))
        throw Errno() << insertable << "Pointer getting failed" << throwable;

    cout << "Pointer now at " << x << ", " << y << endl;

    return 0;
}
catch (Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}

