#include "main.ih"

void parentCat()
{
    while (true)
    {
        cout << "Empty line stops, q breaks echoing: ";
        if (!getline(cin, line))
        {
            cout << "End of input: exiting\n";
            throw 0;
        }

        if (line == "")
            return;

        if (line == "q")
            throw false;

        io << line << endl;
        line.erase();
        getline(io, line);
        cout << "received line: " << line << endl;
    }
}
