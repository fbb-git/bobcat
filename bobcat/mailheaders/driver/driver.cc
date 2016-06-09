/*
                              driver.cc
*/

#include "driver.h"

#include "../mailheaders"

#include <algorithm>
#include <iterator>

#include <bobcat/exception>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    MailHeaders mh(cin, MailHeaders::DONT_READ);

    try
    {
        mh.read();
    }
    catch (exception &err)
    {
        cout << err.what() << endl;
    }

    mh.setHeaderIterator("Received");  

    cout << "=================================== All mail headers:\n";

    copy(mh.begin(), mh.end(), ostream_iterator<string>(cout, "\n"));

    cout << "=============================== First and last but 1 hdr:\n";

    cout << mh[0] << endl <<
            mh[mh.size() - 2] << endl;

    cout << "====================== Received: headers:\n";

    copy(mh.beginh(), mh.endh(),  ostream_iterator<string>(cout, "\n"));

    cout << "====================== Received: headers, reversed order:\n";

    copy(mh.rbeginh(), mh.rendh(),  ostream_iterator<string>(cout, "\n"));

    cout << "====================== all From headers:\n";

    mh.setHeaderIterator("From", MailHeaders::PARTIAL);  

    copy(mh.beginh(), mh.endh(),  ostream_iterator<string>(cout, "\n"));
}
