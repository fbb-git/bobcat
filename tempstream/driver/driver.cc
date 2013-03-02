#include <iostream>
#include "../tempstream"

using namespace std;
using namespace FBB;

int main()
{
    TempStream ts("/tmp/demo");

    ts << "Hello world\n";

    ts.seekg(0);
    string line;
    getline(ts, line);
    cout << line << ", removed: " << ts.fileName() << '\n';
}
