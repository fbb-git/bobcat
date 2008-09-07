/*
                              driver.cc
*/

#include <iostream>
#include <string>

#include "../datetime"

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    DateTime dt;

    if (dt)
        cout << dt << ", RFC 2822 format: " << dt.rfc2822() << "\n";
    else
        cout << "DateTime construction failed\n";

    DateTime utc(dt.time(), DateTime::UTC);

    if (utc)
        cout << utc << "\n";
    else
        cout << "UTC DateTime construction failed\n";

    cout << "Same: " << utc.utc() << endl;

    DateTime loc(utc.time(), DateTime::LOCALTIME);
    cout << loc << endl;

    cout << dt << '\n' <<
            "Enter new day (0 = sun, 6 = sat) and\n"
            "   relativity: < 0: previous week, 0: this week, > 0: next "
                                                                "week: ";
    int day;
    int rel;
    cin >> day >> rel;

    DateTime newDay(dt);
    newDay.setWeekday(static_cast<DateTime::WeekDay>(day),
                rel < 0 ? DateTime::LAST :
                rel > 0 ? DateTime::NEXT :
                          DateTime::THIS_WEEK);
    cout << newDay << "\n\n";

//    cout << "Enter hours to add to the current (local) time: ";
//    int hours;
//    cin >> hours;
//
//    DateTime added(DateTime::LOCALTIME);
//    added += hours * 3600;
//    cout << added;
//
//    cout << "added hrs: " << added.hours() << endl;
//    cout << "dt hrs: " << dt.hours() << endl;
//
//    DateTime diff = added - dt;
//
//    cout << "Difference between added and local time:\n";
//    cout << diff.hours() << endl;
//    cout << diff << endl;
//
//    cout << "Month to set in current time " << dt << ": ";
//    int x;
//    cin >> x;
//    
//    dt.setMonth(x);
//    cout << dt << endl;
//
    return 0;
}




