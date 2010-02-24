#include <iostream>
#include <bobcat/repeat>

using namespace std;
using namespace FBB;

class Object
{
    public:
        void member();
};

void Object::member()
{
    cout << "member called\n";
}

int main(int argc, char **argv)
{
    Object object;

    repeat(argc, object, &Object::member);
}
