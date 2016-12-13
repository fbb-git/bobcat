#include <iostream>

#include <bobcat/extractorfork>

using namespace std;
using namespace FBB;

int main()
{
    ExtractorFork extractor;

    extractor.execute("/bin/cat driver.cc");

    cout << extractor.rdbuf();

    cerr << "Returning: " << extractor.ret() << "\n"
            "again:\n";

    extractor.execute("/bin/cat driver.cc");

    cout << extractor.rdbuf();

    cerr << "Returning: " << extractor.ret() << '\n';

}
