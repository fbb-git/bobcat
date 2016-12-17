#include <iostream>

#include "../stdextractor"

using namespace std;
using namespace FBB;

int main()
{
    StdExtractor extractor;

    extractor.execute("/bin/cat build out");    // out does not exist

    string line;
    getline(extractor, line);
    cout << "First line: " << line << "\n\n";

    extractor.execute("/bin/cat build out");    // out does not exist
    cout << extractor.rdbuf();

    cerr << "Returning: " << extractor.ret() << '\n';
}
