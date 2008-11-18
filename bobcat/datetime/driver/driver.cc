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
    DateTime dt;                        // Current UTC time
    cout << " 1 " << dt << endl;

    DateTime local(DateTime::LOCALTIME); // Current local time
    cout << " 2 " << local << endl;

    DateTime pst(-8 * 60);              // Current PST
    cout << " 3 " << pst << endl;
                                        // current local time
    DateTime modify(dt.time(), DateTime::LOCALTIME);
    cout << " 4 " << modify << endl;

    modify.setDay(1);                   // 1st of this month
    cout << " 5 " << modify << endl;

    modify.setHours(25);                // 01:xx.yy, 2nd of this month
    cout << " 6 " << modify << endl;

    modify.setMinutes(00);              // 01:00.yy, 2nd of this month
    cout << " 7 " << modify << endl;

                                        // 01:00.yy, 2nd of Jan. next year
    modify.setMonth(DateTime::JANUARY, DateTime::NEXT); 
    cout << " 8 " << modify << endl;

    modify.setMonth(-12);               // 01:00.yy, 2nd of Jan. this year
    cout << " 9 " << modify << endl;

    modify.setSeconds(90);               // 01:01.30, 2nd of Jan. this year
    cout << "10 " << modify << endl;

    modify.setTime(dt.time());          // back to current time 
    cout << "11 " << modify << endl;

    modify.setWeekday(DateTime::MONDAY);  // coming Monday
    cout << "12 " << modify << endl;

    modify.setYear(2000);               // some years ago
    cout << "13 " << modify << endl;

    struct tm timeStruct = *local.timeStruct();

    modify.setFields(timeStruct, 0xff);    // use all fields
    cout << "14 " << modify << endl;
            
    DateTime local2(timeStruct, DateTime::LOCALTIME);  // local time 
    cout << "15 " << local2 << endl;

    DateTime local3(timeStruct, 2 * 60);  // local time + 2 hours
    cout << "16 " << local3 << endl;

    DateTime utcStr("Tue Nov 18 15:06:29 2008");
    cout << "17 " << utcStr << " " << utcStr.time() << endl;
    DateTime utcX(1227020789, DateTime::UTC);
    cout << "17 " << utcX << " " << utcX.time() << endl;

    DateTime utcStr2("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME);
    cout << "17 " << utcStr2 << " " << utcStr.time() << endl;
    DateTime utcX2(1227020789, DateTime::LOCALTIME);
    cout << "17 " << utcX2 << " " << utcX.time() << endl;

//    DateTime localStr("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME, +60);
//    cout << "18 " << localStr << endl;
//
    DateTime utcStr3("Tue Nov 18 15:06:29 2008", 0);
    cout << "19 " << utcStr3 << endl;

//    DateTime timeStr3("Tue Nov 18 15:06:29 2008", 60, -60);
//    cout << "20 " << timeStr3 << endl;


//    if (dt)
//        cout << dt << ", RFC 2822 format: " << dt.rfc2822() << "\n";
//    else
//        cout << "DateTime construction failed\n";
//
//    dt.setMonth(-4);
//    time_t sep = dt.time();
//    DateTime sepdt(sep, 4 * 60);
//
//    cout << dt.rfc2822() << endl;
//    cout << sepdt.rfc2822() << endl;

//    DateTime utc(dt.time(), DateTime::UTC);
//
//    if (utc)
//        cout << utc << "\n";
//    else
//        cout << "UTC DateTime construction failed\n";
//
//    cout << "Same: " << utc.utc() << endl;
//
//    DateTime loc(utc.time(), DateTime::LOCALTIME);
//    cout << loc << endl;

//    DateTime rept(dt);
//    cout << dt << '\n' <<
//            "Enter nr weeks ahead and -1 or\n"
//            "nr and month (0: jan) in the next occurrence of nr month ";
//    int nr;
//    int month;
//    cin >> nr >> month;
//
//    if (month == -1)        // nr repetitions
//        rept.setDay(rept.monthDayNr() + nr * 7);
//    else                    // last date is nr of month
//    {   
//        rept.setMonth(static_cast<DateTime::Month>(month), DateTime::NEXT);
//        rept.setDay(nr);
//    }
//    cout << rept << "\n\n";
//
//
//    cout << dt << '\n' <<
//            "Enter new day (0 = sun, 6 = sat) and\n"
//            "   relativity: < 0: previous week, 0: this week, > 0: next "
//                                                                "week: ";
//    int day;
//    int rel;
//    cin >> day >> rel;
//
//    DateTime newDay(dt);
//    newDay.setWeekday(static_cast<DateTime::WeekDay>(day),
//                rel < 0 ? DateTime::LAST :
//                rel > 0 ? DateTime::NEXT :
//                          DateTime::THIS_WEEK);
//    cout << newDay << "\n\n";
//
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




