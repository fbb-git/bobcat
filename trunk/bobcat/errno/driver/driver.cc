#include <iostream>
#include "../errno"
#include <errno.h>

#include <fstream>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    string hello = "hello world";

    try
    {
        try
        {
            Errno e;
            e << hello;
            throw e;
        }
        catch(Errno const &e)
        {
            cerr << e.what() << ", " << e.which() << "\n";
            throw;
        }
    }
    catch(exception const &e)
    {
        cout << "Exception caught: " << e.what() << "\n";
    }

    cerr << "================== second example ===============\n";

    try
    {
        errno = 12;
        Errno e("Prefix text");
        e << ".\n\tThis is the result of errno = " << errno;
        throw e;
    }
    catch(exception const &e)
    {
        cout << "Exception caught: " << e.what() << "\n";
    }

    cerr << "================== third example ===============\n";

    try
    {
        Errno e(12, "Prefix text");
        Errno e2(e);

        cout << sizeof(Errno) << ' ' << sizeof(ostringstream) << ' ' <<
                        sizeof(exception) << endl;

        
//        e2 = e;
        e2 << ".\n\tThis is the result of 12 prefixed initialized";
        throw e2;
    }
    catch(Errno const &e)
    {
        cout << "Exception caught: " << e.what() << ", " << e.which() << "\n";
    }

    cerr << "================== fourth examplle ===============\n";

    try
    {
        throw Errno(99, "Since Special") << ". Hello world " << 1234;

        cerr << "NOT REACHED\n";
    }
    catch (exception const &e)
    {
        cerr << e.what() << ".\n";
    }

    cerr << "================== fifth example ===============\n";

    try
    {
        throw Errno(99, "Obsoleted") << insertable << ". Hello world " << 
                                            1234 << throwable;

        cerr << "NOT REACHED\n";
    }
    catch (exception const &e)
    {
        cerr << e.what() << ".\n";
    }
}






