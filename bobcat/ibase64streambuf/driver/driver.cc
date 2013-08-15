#include "../ibase64streambuf"

#include <iostream>
#include <istream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    switch (argv[1][0])
    {
        case 'e':
        {
            IBase64Streambuf<ENCRYPT> encrypt(cin);
            istream ein(&encrypt);
            cout << ein.rdbuf();
        }
        break;

        case 'd':
        {
            IBase64Streambuf<DECRYPT> decrypt(cin);
            istream din(&decrypt);
            cout << din.rdbuf();
        }
        break;
    
        default:
        {
            IBase64Streambuf<ENCRYPT> encrypt(cin);
            istream ein(&encrypt);

            IBase64Streambuf<DECRYPT> decrypt(ein);
            istream din(&decrypt);
            cout << din.rdbuf();
        }
        break;
    }
}
