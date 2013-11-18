#include "main.ih"

struct xstream: private SBuf, public istream, public ostream
{
    xstream()
    :
        istream(this),
        ostream(this)
    {}
};

int main(int argc, char **argv)
try
{
    xstream inout;

    char buffer[10];

    inout.seekp(12);
    cout << "inout at " << inout.tellg() << '\n';
    inout.put(100);
    inout.get();
    cout << "inout: " << boolalpha << inout.good() << '\n';
    inout.clear();
    inout.seekg(25);
    inout.get();
    inout.read(buffer, 10);
    inout.seekg(-1, ios::beg);

    cout << "inout: " << boolalpha << inout.good() << '\n';
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}
