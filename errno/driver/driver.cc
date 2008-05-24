#include <iostream>
#include "../errno.h"
#include <errno.h>

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
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
        e << ".\n\tThis is the result of 12 prefixed initialized";
        throw e;
    }
    catch(Errno const &e)
    {
        cout << "Exception caught: " << e.what() << ", " << e.which() << "\n";
    }

    cerr << "================== fourth examplle ===============\n";

    try
    {
        throw Errno(99, "Special") << insertable << ". Hello world" << 
                                                    throwable;

        cerr << "NOT REACHED\n";
    }
    catch (exception &e)
    {
        cerr << e.what() << ".\n";
    }

/*
    This won't compile, as the result is an ostream, 
    which can't be copied.

    try
    {
        throw Errno(99, "Thrown: ") << unConst <<
                " a Errno object into which something is inserted";
    }
    catch (Errno const &e)
    {
        cout << e.what() << " " << e.why() << endl;
    }

    catch (ostream const &str)
    {
        cout << "stream is thrown\n";
    }
*/
}






