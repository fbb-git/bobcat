/*
                              errno.cc

   $Id: errno.cc 2 2005-08-19 15:12:51Z frank $

   $Log$
   Revision 1.1  2005/08/19 15:12:52  frank
   Initial revision

   Revision 1.1.1.1  2003/05/28 13:32:23  frank
   Initial installation of FBB::Errno

*/

#include "errno.ih"

Errno::Errno()
:
    d_errno(errno)
{
    initMsg();
}
