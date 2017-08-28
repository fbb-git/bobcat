
#include "qpstreambufbase.ih"

bool QPStreambufBase::encode()
{
    while (true)
    {
        int ch = d_in.get();

        if (not d_in)            // eof encountered
        {
            flush();
            return false;
        }

        if (ch != '\n')
            insert(ch);       
        else
            (this->*d_encode)();
    
        if (d_buffer.length() > 100)
            return true;
    }                
}







