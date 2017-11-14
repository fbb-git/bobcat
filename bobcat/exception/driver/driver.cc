#include <iostream>
#include "../exception"

#include <fstream>
#include <cerrno>

#include <cstring>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    string hello = "hello world";

    try
    {
        try
        {                               // throw exception in which data of
                                        // various types were inserted
            throw Exception() << hello << ' ' << 12.34 << "...";
        }
        catch(exception const &e)
        {
            cerr << "first: " << e.what() << '\n';
            throw;                      // may be rethrown, which is standard
        }
    }
    catch(exception const &e)
    {
        cout << "second: exception caught: " << e.what() << '\n';
    }

    try
    {                               // throw exception in which data of
                                    // various types were inserted
        throw Exception(5) << "third: exception with errno value set";
    }
    catch(exception const &e)
    {
        cerr << "fourth: " << e.what() << '\n'
             << "Exception == " << errno << '\n';
    }

    try
    {
        ofstream out;
        Exception::open(out, "out");

        Exception::open(out, "");
    }
    catch(exception const &e)
    {
        cout << "fifth: " << e.what() << '\n';
    }

    try
    {
        ofstream out;
        Exception::open(out, "out", ios::in | ios::out);
    }
    catch(exception const &e)
    {
        cout << "sixth: " << e.what() << '\n';
    }

    try
    {
        throw Exception(E2BIG) << "Error: " << FBB::errnodescr;
    }
    catch(exception const &e)
    {
        cout << "eighth: " << e.what() << '\n';
    }
    
    cout << "end of program\n";
}







