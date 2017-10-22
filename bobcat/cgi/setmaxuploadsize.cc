#include "cgi.ih"

void CGI::setMaxUploadSize(size_t maxUploadSize, int unit)
{
    unsigned long long newSize = maxUploadSize;
    switch (unit)
    {
        case 'G':
        case 'g':
            newSize <<= 10;
        [[fallthough]]
        
        case 'M':
        case 'm':
            newSize <<= 10;
        [[fallthough]]
        
        case 'K':
        case 'k':
            newSize <<= 10;
        [[fallthough]]

        default:        
            d_maxUploadSize = newSize;
        break;
    }
}

