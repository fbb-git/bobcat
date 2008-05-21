#include "cgi.ih"

CGI::CGI(bool defaultEscape, char const *header, std::ostream &out)
:
    d_method(UNDETERMINED),
    d_escapeValue(defaultEscape),
    d_contentLength(0),
    d_filePath("/tmp/"),
    d_fileNr(1),
    d_contentDisposition("^Content-Disposition: form-data; name=\"([^\"]+)\""),
    d_contentFile("; filename=\"([^\"]+)\""),
    d_activated(false),
    d_maxUploadSize(100ULL * 1024 * 1024)
{
    for_each(d_escape, d_escape + sizeof(d_escape) / sizeof(bool), 
                  *this, &CGI::init);

    d_escapeValue = !d_escapeValue;     // all changes will now change the 
                                        // default
    setMethod();

    if (d_status.length() == 0)
        setQuery();

    if (header)
        out << header << "\r\n\r\n";

}
