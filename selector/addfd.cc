/*
                              selector.cc

   $Id: addfd.cc,v 1.1.1.1 2005-08-19 15:12:52 frank Exp $

   $Log: addfd.cc,v $
   Revision 1.1.1.1  2005-08-19 15:12:52  frank
   The BOBCAT Class and Template Library

   Revision 1.1.1.1  2003/05/31 13:19:21  frank
   Initial import of Selector

   Revision 1.1.1.1  2003/05/31 12:44:34  frank
   Initial import of Selector

*/

#include "selector.ih"

using namespace std;
using namespace FBB;


void Selector::addFd(fd_set *set, int fd)
{
    FD_SET(fd, set);
    if (fd >= d_max)
        d_max = fd + 1;
}

