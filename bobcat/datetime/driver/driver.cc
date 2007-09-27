/*
                              driver.cc
*/

#include "driver.h"

int main(int argc, char **argv, char **envp)
{
    DateTime dt;

    if (dt)
        cout << dt;
    else
        cout << "DateTime construction failed\n";

    DateTime utc(DateTime::UTC);

    if (utc)
        cout << utc;
    else
        cout << "UTC DateTime construction failed\n";

    cout << "Enter hours to add to the current (local) time: ";
    int hours;
    cin >> hours;

    DateTime added(DateTime::LOCALTIME);
    added += hours * 3600;
    cout << added;

    cout << "added hrs: " << added.hours() << endl;
    cout << "dt hrs: " << dt.hours() << endl;

    DateTime diff = added - dt;

    cout << "Difference between added and local time:\n";
    cout << diff.hours() << endl;
    cout << diff << endl;

    cout << "Month to set in current time " << dt << ": ";
    int x;
    cin >> x;
    
    DateTime save(dt);

    dt.setMonth(static_cast<DateTime::Month>(x));
    cout << dt << endl;

    dt = save;
    dt.setMonth(static_cast<DateTime::Month>(x), DateTime::LAST);
    cout << dt << endl;

    dt = save;
    dt.setMonth(static_cast<DateTime::Month>(x), DateTime::NEXT);
    cout << dt << endl;

    return 0;
}




