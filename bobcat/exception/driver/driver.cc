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
            cerr << e.what() << '\n';
            throw;                      // may be rethrown, which is standard
        }
    }
    catch(exception const &e)
    {
        cout << "Exception caught: " << e.what() << '\n';
    }

    try
    {                               // throw exception in which data of
                                    // various types were inserted
        throw Exception(5) << "Exception with errno value set";
    }
    catch(exception const &e)
    {
        cerr << e.what() << '\n'
             << "Errno == " << errno << '\n';
    }

    try
    {
        ofstream out;
        Exception::open(out, "out");

        Exception::open(out, "");
    }
    catch(exception const &e)
    {
        cout << e.what() << '\n';
    }

    try
    {
        ofstream out;
        Exception::open(out, "out", ios::in | ios::out);
    }
    catch(exception const &e)
    {
        cout << e.what() << '\n';
    }

    try
    {
        throw Exception(E2BIG) << "Error: " << FBB::strerror;
    }
    catch(exception const &e)
    {
        cout << e.what() << '\n';
    }
}







