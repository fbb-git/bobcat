    #include <ctime>
    #include <iostream>
    using namespace std;

    int main()
    {
        time_t utc = time(0);
        cout << asctime(gmtime(&utc));
        return 0;
    }
