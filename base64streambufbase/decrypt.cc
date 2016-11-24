#include "base64streambufbase.ih"
#include <iostream>

bool Base64StreambufBase::decrypt()
{
    // reading blocks of 4 characters. 
    // If the first byte is \n then reread it (from the next line).
    // Stop if the first character is not in the set of accepted base64
    // characters

    while (true)
    {
        int b0 = d_in.get();                    // first of 4

        if (b0 == '\n')                         // is a \n: read the next
            b0 = d_in.get();                    // returns 0xff on failure

        if (s_tabStr.find(b0) == string::npos)  // b0 is not in the set of
        {                                       // base64 chars
            d_in.unget();
            return false;                       // signal 'done'
        }

        
        int b1 = d_in.get();                    // continue: there must be
        int b2 = d_in.get();                    // at least 4 characters
        int b3 = d_in.get();

        b0 = indexOf(b0);                       // convert chars to indices:
        b1 = indexOf(b1);                       // their bit patterns are
                                                // stored in max, 3 decrypted 
                                                // characters

                                        
        d_buffer.push_back(
                (b0 << 2)           // 6 bits of b0 become bits 2..7
                | 
                bits<4, 2>(b1)      // bits 4,5 of b1 become bits 0..1
            );

        if (b2 == '=')              // encountered '==': only one output char
            return false;

        b2 = indexOf(b2);

        d_buffer.push_back(
                bits<0, 4, 4>(b1)   // bits 0..3 become bits 4..7
                | 
                bits<2, 4>(b2)      // bits 2..5 become bits 0..3
            );

        if (b3 == '=')              // encountered '==': two output chars
            return false;

        d_buffer.push_back(
                bits<0, 2, 6>(b2)   // bits 0..1 become bits 6..7
                | 
                indexOf(b3)         // all 6 bits of b3
            );

        if (d_buffer.size() > 100)  // flush if the buffer is full
            return true;            
    }
}




