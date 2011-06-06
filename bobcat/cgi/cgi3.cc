#include "cgi.ih"

// Deprecated. Kept for backward compatibility only
#include "../iuo/iuo"

CGI::CGI(CGI const &&tmp)
:
    d_method(tmp.d_method),
    d_escapeValue(tmp.d_escapeValue),

    d_param( move(tmp.d_param) ),
    d_query( move(tmp.d_query) ),
    d_boundary( move(tmp.d_boundary) ),

    d_contentLength(tmp.d_contentLength),

    d_filePath( move(tmp.d_filePath) ),
    d_filePrefix( move(tmp.d_filePrefix) ),

    d_fileNr(tmp.d_fileNr),

    d_contentDisposition( move(tmp.d_contentDisposition) ),
    d_contentFile( move(tmp.d_contentFile) ),
    d_status( move(tmp.d_status) ),

    d_activated(tmp.d_activated),
    d_maxUploadSize(tmp.d_maxUploadSize)
{
    static bool called = false;
    deprecated__(called, "CGI::CGI(CGI const &&)");

    memcpy(d_escape, tmp.d_escape, sizeof(d_escape));
}





