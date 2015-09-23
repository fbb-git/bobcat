#include "main.hh"

void childEchoes()
{
    while (getline(cin, line))
    {
        cerr << "Child receives: " << line << endl;
        cout << "Child saw: " << line << endl;
    }
}
