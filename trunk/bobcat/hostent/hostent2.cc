#include "hostent.ih"

Hostent::Hostent(Hostent const &&tmp)
{
    swap(const_cast<Hostent &>(tmp));
    const_cast<Hostent &>(tmp).h_name = 0;  // prevent tmp's ~Hostent from
                                            // deleting wild pointers
}

