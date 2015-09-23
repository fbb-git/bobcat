#include "main.hh"

void parentCloseIn()
{
    io << "Hello world" << endl;

    close();

    while (getline(io, line))
        cout << line << endl;

}
