#include "mailheaders.ih"

MailHeaders::const_hdr_iterator::Comparator 
    MailHeaders::const_hdr_iterator::s_comparator[] = 
{
    fail,
    initial,
    partial,
    full,
    caseInitial,
    casePartial,
    caseFull
};

