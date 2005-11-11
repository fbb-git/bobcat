/*
                              driver.cc
*/

#include "driver.h"

#ifndef _INCLUDED_MAILHEADERS_H_
#include "../mailheaders.h"
#endif

#ifndef _SYSINC_ALGORITHM_
#include <algorithm>
#define _SYSINC_ALGORITHM_
#endif

#ifndef _SYSINC_ITERATOR_
#include <iterator>
#define _SYSINC_ITERATOR_
#endif

#ifndef _INCLUDED_ERRNO_H_
#include <fbb/errno.h>
#endif

using namespace std;
using namespace FBB;

MailHeaders *mp;

void showFirst(MailHeaders::HdrLine const &lines)
{
    cout << mp->at(lines[0]) << endl;
}

int main(int argc, char **argv, char **envp)
{
    MailHeaders mh(cin, MailHeaders::DONT_READ);
    mp = &mh;

    try
    {
        mh.read();
    }
    catch (Errno &err)
    {
        cout << err.what() << endl;
    }


    cout << "=================================== All mail headers:\n";

    copy(mh.begin(), mh.end(), ostream_iterator<string>(cout, "\n"));

    cout << "=============================== First and last but 1 hdr:\n";

    cout << mh[0] << endl <<
            mh[mh.size() - 2] << endl;

    cout << "====================== First lines of Received: headers:\n";

    mh.setHeaderIterator("Received:");

    for_each(mh.beginh(), mh.endh(), showFirst);

    cout << "====================== All lines of Received: headers:\n";

    for (MailHeaders::const_iterator it = mh.beginh(); it != mh.endh(); it++)
    {
        for 
        (
            vector<unsigned>::const_iterator nr = it->begin(); 
                nr != it->end();
                    nr++
        )
            cout << mh[*nr] << endl;

        cout << "+++++++++++++++++++++++++++++++" << endl;
    }

    cout << "===== reversed order:  First lines of Received: headers:\n";

    for_each(mh.rbeginh(), mh.rendh(), showFirst);

    return 0;
}





