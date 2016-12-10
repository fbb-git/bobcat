#include "../extractorfork.h"

#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
    ExtractorFork extractor;

    extractorfork.execute("/bin/cat main.cc");

    cout << extractorfork.in().rdbuf();

    int ret = extractorfork.waitForChild();
    cerr << "Returning: " << ret << '\n';
}
