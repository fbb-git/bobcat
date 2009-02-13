#include <iostream>

#include <bobcat/inetaddress>
#include <bobcat/errno>

using namespace std;
using namespace FBB;

InetAddress X()
{
    class A: public InetAddress
    {
        public:
        A(uint16_t port)
        :
            InetAddress(port)
        {}
    };

    return A(2000);
}

int main(int argc, char **argv)
try
{
    InetAddress const &ia = X();

    cout << "A InetAddress was constructed for port " << ia.port() <<
            endl;
    cout << "It has the generic `ANY' address: " << 
            ia.dottedDecimalAddress() << endl;

    return 0;
}
catch (Errno const &e)
{
    cout << "Exception: " << e.what() << endl;
}

