#ifndef _INCLUDED_HOSTNAME_H_
#include "../hostname.h"
#endif

#ifndef _INCLUDED_IOSTREAM_
#include <iostream>
#define _INCLUDED_IOSTREAM_
#endif

#ifndef _INCLUDED_INETADDRESS_H_
#include <fbb/inetaddress.h>
#endif

#ifndef _INCLUDED_ERRNO_H_
#include <fbb/errno.h>
#endif

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    while (true)
    {
        cout << "Enter name or address:\n";

        string s;

        if (!getline(cin, s))
            return 0;

        if (s == "")
            break;

        try
        {
            Hostname h(s);

            cout << "Official name:\n";
                cout << h.hostname() << endl;

            cout << "Aliases:\n";
            for (unsigned idx = 0; idx < h.nAliases(); idx++)
                cout << h.alias(idx) << " ";
            cout << endl;

            cout << "Adresses:\n";
            for (unsigned idx = 0; idx < h.nAddresses(); idx++)
                cout << h.dottedDecimalAddress(idx) << " ";
            cout << endl;
        }
        catch (Errno const &err)
        {
            cout << err.what() << endl;
        }
    }
/*
    cout << "Now using InetAddress for the local host\n";

    try
    {
        Hostname h(InetAddress(2048));

        cout << "Name: " << h.name() << endl;

        cout << "Aliases:\n";
        for (unsigned idx = 0; idx < h.nNames(); idx++)
            cout << h.name(idx) << " ";
        cout << endl;

        cout << "Adresses:\n";
        for (unsigned idx = 0; idx < h.nAddresses(); idx++)
            cout << h.address(idx) << " ";
        cout << endl;
    }
    catch (Errno const &err)
    {
        cout << err.which() << endl;
    }
*/
    return 0;
}
