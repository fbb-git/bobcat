    #include <ctime>
    #include <iostream>
    using namespace std;

    int main()
    {
        time_t utcSeconds = time(0);   // UTC time

        struct tm ts;
        gmtime_r(&utcSeconds, &ts);    // fill the ts struct

        cout << ts.tm_hour << " " << asctime(&ts);  // display it

                                    // this number of seconds is returned
                                    // when computing secs from struct tm
        time_t retrievedUtcSeconds = mktime(&ts);
        gmtime_r(&retrievedUtcSeconds, &ts);            // refill the struct tm
        cout << asctime(&ts);


        int correction = utcSeconds - retrievedUtcSeconds;

        cout << correction << endl;  // retrieve seconds


        time_t correctedUtcSeconds = retrievedUtcSeconds + correction;
        gmtime_r(&correctedUtcSeconds, &ts); 
        cout << asctime(&ts);

        cout << utcSeconds - mktime(localtime_r(&utcSeconds, &ts)) << endl;
        return 0;
    }

/*
    Compute the correction for the current time zone It can also be computed
    as mktime(locatime()) - mktime(gmtime())

    To compute the (UTC) number of seconds from a struct tm representing the
    time in UTC compute mktime(gmtime(tm)) + correction or compute
    mktime(localtime(tm))

    To compute a struct tm for a certain display zone, add the zone to utc
    info and display according to the broken down time using gmtime().

    To compute the matching utc time: compute 
        mktime(localtime(tm)) - zoneshift

    Assuming a local time in a certain zone shift is available in a struct tm
    compute mktime(localtime(tm) - zoneshift to obtain the utc time

*/

