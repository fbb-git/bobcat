/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <sstream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main(int argc, char **argv, char **envp)
{
    DateTime dt;                        // Current UTC time
    cout << " 1 " << dt << endl;

    DateTime local(DateTime::LOCALTIME); // Current local time

    cout << " 2 " << local << "\n"
            "    Y: " << local.year() <<
                " M: " << local.month() << 
                " D: " << local.monthDayNr() << "\n"
            "    H: " << local.hours() << 
                " M: " << local.minutes() <<
                " S: " << local.seconds() << "\n"
            "    zoneshift: " << local.displayZoneShift() << 
                " weekday: " << local.weekday() << "\n"
            "    yrDay: " << local.yearDay() <<
                " yrDayNr: " << local.yearDayNr() <<
                " weekNr: " << local.weekNr() << endl;

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

    DateTime utcX(utcStr.time(), DateTime::UTC);
    cout << "18 " << utcX << " " << utcX.time() << endl;

    DateTime localStr("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME);
    cout << "19 " << localStr << endl;

    DateTime localStr2("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME, +60);
    cout << "20 " << localStr2 << endl;

    DateTime timeStr3("Tue Nov 18 15:06:29 2008", 120, 60);
    cout << "21 " << timeStr3 << endl;

    timeStr3 += 31;
    cout << "22 " << timeStr3 << endl;

    timeStr3 -= 7 * 60 + 15 * 3600;
    cout << "23 " << timeStr3 << endl;

    timeStruct.tm_sec  = 30;
    timeStruct.tm_min  = 30;
    timeStruct.tm_hour = 4;
    timeStruct.tm_mday = 1;
    timeStruct.tm_mon  = 1;
    timeStruct.tm_year = 0;

    timeStr3 += timeStruct;
    cout << "24 " << timeStr3 << endl;

    timeStr3 -= timeStruct;
    cout << "25 " << timeStr3 << endl;

    timeStruct = *timeStr3.timeStruct();
    --timeStruct.tm_mday; 
    timeStruct.tm_year -= (1970 - 1900);
    timeStr3 -= timeStruct;
    cout << "26 " << timeStr3 << endl;

    DateTime dst(DateTime::LOCALTIME);
    dst.setMonth(DateTime::SEPTEMBER);
    cout << "27 " << dst << ", DST: " << dst.dst() << endl;

    cout << "28 " << dst.rfc2822() << endl;
    cout << "29 " << dst.rfc3339() << endl;

    DateTime utcDst(dst.utc());

    cout << "30 " << utcDst << endl;

    cout << "31 " << utcDst.localTime() << endl;

    cout << "32 " << dst.timeZoneShift(3 * 60) << endl;

    cout << "33 " << utcDst.timeZoneShift(3 * 60) << endl;

    istringstream ins("Tue Nov 18 15:06:29 2008");
    ins >> dst;

    cout << "34 " << dst << endl;

    return 0;
}




