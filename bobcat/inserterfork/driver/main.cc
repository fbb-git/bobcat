#include "../inserterfork/inserterfork.h"

#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
    InserterFork inserter;

    inserterfork.execute("/usr/bin/mail -s inserter frank@localhost");

    inserterfork.out() << "hello world\n";

    int ret = inserterfork.stop();
    cerr << "Returning: " << ret << '\n';
}
