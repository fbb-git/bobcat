#include "../hash"

using namespace FBB;
using namespace std;

int main(int argc, char *const *const argv)
{
    pair<char const *, int> d[10];

    HashCharPtr<int> hcp(d, d + 10);
    return 0;
}
