
#include <fstream>
#include <iostream>

#include <bobcat/exception>
#ifdef BOBCAT
    #include <bobcat/cidr>
#else
    #include "cidr"
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    enum Spec
    {
        NONE,
        FILE,
        CIN
    };
    
    Spec spec = CIN;
    ifstream in;

    if (argc > 1)
    {
        Exception::open(in, argv[1]);       // file containing cidr-specs
        spec = FILE;
    }
    
    while (true)
    {
        string cidrSpec;
        if (spec == CIN)
        {
            cout << "Specify cidr (empty to quit): ";
            if (!getline(cin, cidrSpec) || cidrSpec.empty())
                break;
        }
        try
        {
            Cidr cidr;

            switch (spec)
            {
                case NONE:
                return 0;

                case FILE:
                    cidr.setCidr(in);
                    spec = NONE;
                break;

                case CIN:
                    cidr.setCidr(cidrSpec);
            }
        
            while (true)
            {
                cout << "Specify address to test (empty to " <<
                    (spec == CIN ? "respec. CIDR" : "quit") << "): ";
                string address;
                if (!getline(cin, address) || address.empty())
                    break;
            
                if (!cidr.match(address))
                {
                    cout << "Address " << address << " not in ";
                    if (spec == CIN)
                        cout << cidrSpec << '\n';
                    else
                        cout << "specifications in " << argv[1] << '\n';
                }
                else
                    cout << "Address " << address << " in " << cidr.cidr() << 
                                                                        "\n"
                        "Lowest address: " << cidr.first() << "\n"
                        "Highest address: " << cidr.last() << "\n"
                        "CIDR mask: " << cidr.mask() << "\n"
                        "Address: " << cidr.address() << '\n';
            }
        }
        catch (exception const &err)
        {
            cout << "Oops... " << err.what() << "\n"
                    "Try again...\n";
        }
    }
}


