#include <iostream>
#include <istream>

#include <bobcat/randbuffer>
#include <bobcat/a2x>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "expect: nruns min max seed\n";
        return 1;
    }

    Randbuffer rb(A2x(argv[2]), A2x(argv[3]), A2x(argv[4]).to<size_t>());

    istream istr(&rb);

    for (int idx = A2x(argv[1]); idx--; )
    {
        int c;
        if (!(istr >> c))
        {
            cout << "extraction failed\n";
            break;
        }    
        cout << "next: " << c << endl;
    }

    int count = 0;
    while (istr.unget())
        count++;

    cout << "number of successful unget()-calls: " << count << endl;
    istr.clear();
    istr >> count;
    cout << "and read: " << count << endl;
    
    return 0;
}
