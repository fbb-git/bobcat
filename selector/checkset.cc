/*
                              selector.cc

   $Id: checkset.cc 2 2005-08-19 15:12:51Z frank $

   $Log$
   Revision 1.1  2005/08/19 15:12:52  frank
   Initial revision

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

