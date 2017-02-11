#include "main.ih"

void display(Map const &table)
{
    for (auto const &keyValue: table)   // display class names and the classes
    {                                   // they depend on.
        cout << keyValue.first << ' ';
        for (auto const &dep: keyValue.second)
            cout << dep << ' ';
        cout << '\n';
    }
}
