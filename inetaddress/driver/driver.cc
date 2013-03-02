#ifndef INCLUDED_INETADDRESS_H_
#include "../inetaddress.h"
#endif

using namespace std;
using namespace FBB;

InetAddress x()
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


int main(int argc, char **argv, char **envp)
{
    InetAddress ia = x();

    try
    {
        cout << "A InetAddress was constructed for port " << ia.port() <<
                endl;
        cout << "It has the generic `ANY' address: " << 
                ia.dottedDecimalAddress() << endl;
    }
    catch (Errno const &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
