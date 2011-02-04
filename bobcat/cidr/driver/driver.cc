#include <iostream>
#include <iterator>

#include <bobcat/errno>
#ifdef BOBCAT
    #include <bobcat/cidr>
#else
    #include "cidr"
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Provide cidr and address as arg1 and arg2\n";
        return 1;
    }

    Cidr cidr(argv[1]);
    if (!cidr.match(argv[2]))
        cout << "Didn't match 
    {

}

