#include <iostream>
#include <bobcat/irandstream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    IRandStream in(1000);

    for (; argc--; )
    {
        size_t random;
        in >> random;
        cout << random << endl;
    }

    return 0;
}

