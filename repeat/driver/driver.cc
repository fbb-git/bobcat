#include <iostream>
#include <iterator>
#include <algorithm>

#include "../repeat"

using namespace std;
using namespace FBB;

class Object
{
    public:
        void member(int argc, char **argv) const;
        void member2(size_t &rept, int argc, char **argv);
};

void Object::member(int argc, char **argv) const
{
    cout << "member called\n";
    copy(argv, argv + argc, ostream_iterator<char const *>(cout, "\n"));
}

void Object::member2(size_t &rept, int argc, char **argv)
{
    cout << "member2 called, iteration " << rept++ << "\n";
    copy(argv, argv + argc, ostream_iterator<char const *>(cout, "\n"));
}

void fun()
{
    cout << "Fun called\n";
}

int main(int argc, char **argv)
{
    Object object;

    cout << "\n"
            "*** The number of arguments determines the repeat-count ***\n\n";

    cout << "Fun without arguments:\n";
    repeat(argc, fun);

    cout << "Object receiving argc and argv:\n";
    repeat(argc, object, &Object::member, argc, argv);

    cout << "Object receiving argc and argv, showing the iteration count:\n";
    size_t count = 0;
    repeat(argc, object, &Object::member2, count, argc, argv);

    Object const obj;
    cout << "Const Object receiving argc and argv:\n";
    repeat(argc, obj, &Object::member, argc, argv);

}



