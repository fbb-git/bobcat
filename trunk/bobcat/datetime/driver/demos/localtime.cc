    #include <ctime>
    #include <iostream>
    using namespace std;

    int main()
    {
        time_t utc = time(0);
        struct tm *ts;
        time_t local = mktime(ts = gmtime(&utc));
        
        cout << ts->tm_hour << ' ' << utc - local << endl;
        return 0;
    }
