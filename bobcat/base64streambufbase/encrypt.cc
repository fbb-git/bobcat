
#include "base64streambufbase.ih"

bool Base64StreambufBase::encrypt()
{
    while (true)
    {
        int c0 = d_in.get();
        if (!d_in)
            return d_buffer.size();
        
        int c1 = d_in.get();
        int c2 = d_in.get();

        d_buffer.push_back(s_tabStr[ bits<2, 6>(c0) ]);
        d_buffer.push_back(s_tabStr[ bits<0, 2, 4>(c0) | bits<4, 4>(c1) ]);

        if (c1 == EOF)
        {
            d_buffer += "==\n";
            return true;
        }
        d_buffer.push_back(s_tabStr[ bits<0, 4, 2>(c1) | bits<6, 2>(c2) ]);

        if (c2 == EOF)
        {
            d_buffer += "=\n";
            return true;
        }

        d_buffer.push_back(s_tabStr[ bits<0, 6>(c2)]);
        if (d_buffer.size() == 76)
        {
            d_buffer.push_back('\n');
            return true;
        }
    }        
}







