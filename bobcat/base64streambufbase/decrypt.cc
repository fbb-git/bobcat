#include "base64streambufbase.hh"
#include <iostream>

bool Base64StreambufBase::decrypt()
{
    while (true)
    {
        int b0 = d_in.get();

        if (b0 == '\n')
            b0 = d_in.get();

        if (s_tabStr.find(b0) == string::npos)
        {
            d_in.unget();
            return false;
        }
        int b1 = d_in.get();
        int b2 = d_in.get();
        int b3 = d_in.get();

        b0 = indexOf(b0);
        b1 = indexOf(b1);

        d_buffer.push_back((b0 << 2) | bits<4, 2>(b1));

        if (b2 == '=')
            return false;

        b2 = indexOf(b2);
        d_buffer.push_back(bits<0, 4, 4>(b1) | bits<2, 4>(b2));

        if (b3 == '=')
            return false;

        d_buffer.push_back(bits<0, 2, 6>(b2) | indexOf(b3));

        if (d_buffer.size() > 100)
            return true;            
    }
}




