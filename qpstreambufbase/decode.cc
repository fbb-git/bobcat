#include "qpstreambufbase.ih"
#include <iostream>

// returns true if the buffer must be flushed, otherwise return false
//  

bool QPStreambufBase::decode()
{
    // read d_in character by character
    //  if the character != '=' then store the character in the buffer
    //  otherwise if the next char is \n then store \n, otherwise 
    //  convert the character from the next two hex-value representing
    //  characters, otherwise (at EOF) return false.

    while (true)
    {
        int b0 = d_in.get();                    // get a character

        if (b0 == '=')                          // found a '=' char
        {
            b0 = d_in.get();                    // get the next char
            if (b0 == '\n')                     // =\n means soft line break
                continue;                       // and so not a real \n

            int b1 = d_in.get();            // get 2nd of 2 hex chars
                                            // convert to real char
            b0 = (s_hexChars.find(b0) << 4) + s_hexChars.find(b1);
        }

        if (!d_in)
            return false;

        d_buffer.push_back(b0);

        if (d_buffer.size() > 100)  // flush if the buffer is full
            return true;            
    }
}







