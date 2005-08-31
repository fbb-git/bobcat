#include "inetaddress.ih"

std::string InetAddress::dottedDecimalAddress() const throw (Errno)
{
    return GetHostent::addressToString("InetAddress::getAddress()", 
                &d_address.sin_addr);
}

