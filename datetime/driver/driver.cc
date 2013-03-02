/*
                              driver.cc
*/

#include <iostream>
#include <string>
#include <sstream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime dt;                        // Current UTC time
    cout << " 1: " << dt << " (UTC Time)\n";

    DateTime local(DateTime::LOCALTIME); // Current local time

    cout << " 2: " << local << " (Local Time (LT))\n"
            "    Y: " << local.year() << " M: " << local.month() << 
                                    " D: " << local.monthDayNr() << "\n"
            "    H: " << local.hours() << " M: " << local.minutes() <<
                                    " S: " << local.seconds() << "\n"
            "    zoneshift: " << local.displayZoneShift() << 
                                    " weekday: " << local.weekday() << "\n"
            "    yrDay: " << local.yearDay() << 
                                    " yrDayNr: " << local.yearDayNr() <<
                                    " weekNr: " << local.weekNr() << endl;

    DateTime pst(-8 * 60);              // Current PST
    cout << " 3: " << pst << " (Current PST)\n";

                                        // current local time
    DateTime modify(dt.time(), DateTime::LOCALTIME);
    cout << " 4: " << modify << " (LT created from UTC)\n";

    modify.setDay(1);                   // 1st of this month
    cout << " 5: " << modify << " (LT at 1st of month)\n";

    modify.setHours(25);                // 01:xx.yy, 2nd of this month
    cout << " 6: " << modify << " (previous LT at 2nd of month 01:xx;yy)\n";

    modify.setMinutes(00);              // 01:00.yy, 2nd of this month
    cout << " 7: " << modify << " (prev. LT at 00 min.)\n";

                                        // 01:00.yy, 2nd of Jan. next year
    modify.setMonth(DateTime::JANUARY, DateTime::NEXT); 
    cout << " 8: " << modify << " (prev. LT at jan next yr)\n";

    modify.setMonth(-12);               // 01:00.yy, 2nd of Jan. this year
    cout << " 9: " << modify << " (prev. LT at jan this yr\n";

    modify.setSeconds(90);               // 01:01.30, 2nd of Jan. this year
    cout << "10: " << modify << " (prev. LT at hh:01:30)\n";

    modify.setTime(dt.time());          // back to current time 
    cout << "11: " << modify << " (LT again)\n";

    modify.setWeekday(DateTime::MONDAY);  // coming Monday
    cout << "12: " << modify << " (LT next monday (or now's monday))\n";

    modify.setYear(2000);               // some years ago
    cout << "13: " << modify << " (LT at 2000)\n";

    struct tm timeStruct = *local.timeStruct();

    modify.setFields(timeStruct, 0xff);    // use all fields
    modify = modify.utc();
    cout << "14: " << modify << " (UTC via LT in timeStruct)\n";
            
    DateTime local2(timeStruct, DateTime::LOCALTIME);  // local time 
    cout << "15: " << local2 << " (LT again)\n";

    DateTime local3(timeStruct, 2 * 60);  
    cout << "16: " << local3 << " (LT + 2 hours)\n";


    cout << "\n"
            "Using UTC time string `Tue Nov 18 15:06:29 2008'\n";

    DateTime utcStr("Tue Nov 18 15:06:29 2008");    // LT string
    cout << "17: " << utcStr << " " << utcStr.time() << " (UTC timestring)\n";

    DateTime utcX(utcStr.time(), DateTime::UTC);
    cout << "18: " << utcX << " " << utcX.time() << " (same)\n";

    DateTime localStr("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME);
    cout << "19: " << localStr << " (creating LT)\n";

    DateTime localStr2("Tue Nov 18 15:06:29 2008", DateTime::LOCALTIME, +60);
    cout << "20: " << localStr2 << " (creating  LT + 1 hr (== UTC + 2 hr))\n";

    DateTime timeStr3("Tue Nov 18 15:06:29 2008", 120, 60);
    cout << "21: " << timeStr3 << " (creating  UTC + 2 + 1 hr))\n";

    timeStr3 += 31;
    cout << "22: " << timeStr3 << " (same, 15:07:00)\n";

    timeStr3 -= 7 * 60 + 15 * 3600; 
    cout << "23: " << timeStr3 << " (same, 03:00:00)\n";

    timeStruct.tm_sec  = 30;
    timeStruct.tm_min  = 30;
    timeStruct.tm_hour = 4;
    timeStruct.tm_mday = 1;
    timeStruct.tm_mon  = 1;
    timeStruct.tm_year = 0;

    timeStr3 += timeStruct;
    cout << "24: " << timeStr3 << " (added 1 month, 1 day, 4:30:30)\n";

    timeStr3 -= timeStruct;
    cout << "25: " << timeStr3 << " (subtracted that again)\n";

    timeStruct = *timeStr3.timeStruct();
    --timeStruct.tm_mday; 
    timeStruct.tm_year -= (1970 - 1900);
    timeStr3 -= timeStruct;
    cout << "26: " << timeStr3 << " (begin of the epoch)\n";

    DateTime dst(DateTime::LOCALTIME);
    dst.setMonth(DateTime::AUGUST);
    cout << "27: " << dst << ", DST: " << dst.dst() << 
                                            " (LT in aug., show dst)\n";

    cout << "28: " << dst.rfc2822() << " (same, rfc 2822)\n";
    cout << "29: " << dst.rfc3339() << " (same, rfc 3339)\n";

    dst.setMonth(DateTime::JANUARY);
    cout << "30: " << dst << ", DST: " << dst.dst() << 
                                            " (LT in jan., show dst)\n";

    cout << "31: " << dst.rfc2822() << " (same, rfc 2822)\n";
    cout << "32: " << dst.rfc3339() << " (same, rfc 3339)\n";


    DateTime utcDst(dst.utc());

    cout << "33: " << dst.timeZoneShift(3 * 60) << " (UTC + 3 time zones)\n";
    cout << "34: " << dst << " (time in jan. again)\n";

    cout << "35: " << utcDst << " (same, UTC)\n";

    cout << "36: " << utcDst.localTime() << " (same, LT)\n";

    cout << "37: " << utcDst.timeZoneShift(3 * 60) << 
                                            " (UTC + 3 time zones)\n";

    istringstream ins("Tue Nov 18 15:06:29 2008");
    ins >> dst;

    cout << "\n"
            "Extracting `" << ins.str() << "'\n";
    cout << "38: " << dst << " (extracted)\n";
    cout << "39: " << dst.utc() << " (same, UTC)\n";

    ins.str("Fri Jul 18 15:06:29 2008");
    ins >> dst;

    cout << "\n"
            "Extracting `" << ins.str() << "'\n";
    cout << "40: " << dst << " (extracted)\n";
    cout << "41: " << dst.utc() << " (same, UTC)\n";

    return 0;
}




