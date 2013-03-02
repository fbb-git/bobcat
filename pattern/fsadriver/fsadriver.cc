/*
                              fsadriver.cc

   $Id: fsadriver.cc,v 1.1.1.1 2005-08-19 15:12:52 frank Exp $

   $Log: fsadriver.cc,v $
   Revision 1.1.1.1  2005-08-19 15:12:52  frank
   The BOBCAT Class and Template Library

   Revision 1.1.1.1  2003/04/19 14:24:00  frank
   Installation of Pattern

*/

#include "fsadriver.h"

#ifndef _INCLUDED_PATTERN_H_
#include "../pattern.ih"
#endif

using namespace std;
using namespace FBB;


int main(int argc, char **argv, char **envp)
{
    string line;
    PerlSetFSA fsa;

    while (true)
    {
        cout << "line to convert: ";
        if (!getline(cin, line) || line.empty())
            break;

        fsa.convert(line);
    }

    return 0;
}
