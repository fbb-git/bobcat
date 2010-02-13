#include <iostream>
#include "../fswap"

class Demo
{
    std::ostream &d_out;
    size_t d_value;

    public:
        Demo(std::ostream &out = std::cerr, size_t value = 0)
        :
            d_out(out),
            d_value(value)
        {}

        void show(char const *msg)
        {
            d_out << msg << ". Value: " << d_value << '\n';
        }
};


using namespace std;

int main()
{
    Demo d1;
    Demo d2(cout, 12);

    FBB::fswap(d1, d2);

    d1.show("This is d1");              // to cerr: 12
    d2.show("This is d2");              // to cout: 0
}






