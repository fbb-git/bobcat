#include <iostream>

#include <bobcat/coutextractor>

using namespace std;
using namespace FBB;

int main()
{
    CoutExtractor extractor;

    extractor.execute("/bin/cat driver.cc");

    cout << extractor.rdbuf();

    cerr << "Returning: " << extractor.ret() << "\n"
            "again:\n";

    extractor.execute("/bin/cat driver.cc");

    cout << extractor.rdbuf();

    cerr << "Returning: " << extractor.ret() << '\n';

}
