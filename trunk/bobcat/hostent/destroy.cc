#include "hostent.ih"

void Hostent::destroy()
{
    if (h_name = 0)
        return;

    delete h_name;

    if (h_aliases)
    {
        for (char **ptr = h_aliases; *ptr; ++ptr)   // delete aliases entries
            delete *ptr;
        delete [] h_aliases;                        // and the array itself.
    }

    delete h_addr_list;
}
