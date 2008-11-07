        time_t seconds = time(0);
        tm timeStruct = *gmtime(&seconds);
    
        DateTime tmp(&timeStruct);

        tmp -= timeStruct;
        cout << tmp << endl;
