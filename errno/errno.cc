/*
                              errno.cc

   $Id: errno.cc,v 1.1.1.1 2005-08-19 15:12:52 frank Exp $

   $Log: errno.cc,v $
   Revision 1.1.1.1  2005-08-19 15:12:52  frank
   The BOBCAT Class and Template Library

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
