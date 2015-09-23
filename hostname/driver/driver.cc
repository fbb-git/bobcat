#include <iostream>

#include <bobcat/hostname>
#include <bobcat/exception>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    while (true)
    {
        cout << "Enter name or address:\n";

        string str;

        if (!getline(cin, str))
            return 0;

        if (str == "")
            break;

        try
        {
            Hostname h(str);

            cout << "Official name:\n";
                cout << h.hostname() << endl;

            cout << "Aliases:\n";
            for (size_t idx = 0; idx < h.nAliases(); idx++)
                cout << h.alias(idx) << " ";
            cout << endl;

            cout << "Adresses:\n";
            for (size_t idx = 0; idx < h.nAddresses(); idx++)
                cout << h.dottedDecimalAddress(idx) << " ";
            cout << endl;
        }
        catch (exception const &err)
        {
            cout << err.what() << endl;
        }
    }
}



