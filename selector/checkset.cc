/*
                              selector.cc

   $Id: checkset.cc,v 1.1.1.1 2005-08-19 15:12:52 frank Exp $

   $Log: checkset.cc,v $
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


int Selector::checkSet(int *index, fd_set &set)
{
    int &idx = *index;

    while (idx < d_max && !FD_ISSET(idx, &set))
        ++idx;

    return idx == d_max ? -1 : idx++;
}

