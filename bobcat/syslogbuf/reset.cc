#include "syslogbuf.hh"

void Syslogbuf::reset(string const &ident, Facility facility, int option)
{
    delete d_data;

    d_data = new Data{ident};
    openlog(d_data->ident.c_str(), option, facility);
    setp(0, 0);                         // no buffer yet
}
