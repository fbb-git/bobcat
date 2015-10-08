#include "multistreambuf.ih"

bool MultiStreambuf::remove(ostream &os, Mode mode)
{
    bool ret = false;

    while (true)
    {
        auto iter = find_if(d_os.begin(), d_os.end(), 
            [&](stream &entry)
            {
                return &entry.ostream() == &os;
            }
        );

        if (iter == d_os.end())
            return ret;

        switch (mode)
        {
            case ALL:
            case ONCE:
                ret = true;
                d_os.erase(iter);
                if (mode == ONCE)
                    return ret;
            break;

            default:
            return false;
        }
    }
}
