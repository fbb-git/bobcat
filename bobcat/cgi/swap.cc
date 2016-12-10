#include "cgi.ih"

void CGI::swap(CGI &rhs)
{
    fswap(*this, rhs, 
                d_query, d_boundary, 
                d_filePath, d_filePrefix,
                d_contentDisposition, d_contentFile, 
                d_status
    );

}



