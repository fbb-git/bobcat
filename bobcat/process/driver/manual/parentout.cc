#include "main.hh"

void parentOut()
{
    size_t count = 0;

    while (getline(io, line))
        cout << ++count<< ": " << line << endl;
}
