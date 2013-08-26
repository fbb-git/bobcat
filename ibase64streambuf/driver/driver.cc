#include <iostream>
#include <istream>

#include <bobcat/ibase64streambuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    switch (argv[1][0])
    {
        case 'e':
        {
            IBase64Streambuf<ENCRYPT> encode(cin);
            istream ein(&encode);
            cout << ein.rdbuf();
        }
        break;

        case 'd':
        {
            IBase64Streambuf<DECRYPT> decode(cin);
            istream din(&decode);
            cout << din.rdbuf();
        }
        break;
    
        case 'b':
        {
            IBase64Streambuf<ENCRYPT> encode(cin);
            istream ein(&encode);

            IBase64Streambuf<DECRYPT> decode(ein);
            istream din(&decode);
            cout << din.rdbuf();
        }
        break;

        default:
            cout << "Usage: " << argv[0] << " [edb] < infile > outfile\n"
                    "to base64 -e-ncode, -d-ecode or -b-oth\n";
        break;
    }
}

