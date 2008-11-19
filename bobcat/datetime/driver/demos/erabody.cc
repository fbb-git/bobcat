time_t seconds = time(0);
tm timeStruct = *gmtime(&seconds);

DateTime tmp(timeStruct);
cout << tmp << endl;

--timeStruct.tm_mday;       // days start at 1: subtract 1 less than
                            // the current day number to get '01'

timeStruct.tm_year -= (1970 - 1900);    // era starts at 1970, tm_year
                                        // is relative to 1900.

tmp -= timeStruct;
cout << tmp << endl;
