#include <iostream>

#include "../binops"

class Demo
{
    friend std::ostream &operator<<(std::ostream &out, Demo const &demo);
    int d_value;

    public:
        Demo(int value = 0)
        :
            d_value(value)
        {}
    
        Demo &operator+=(Demo const &rhs)
        {
            d_value += rhs.d_value;
            return *this;
        }
};

std::ostream &operator<<(std::ostream &out, Demo const &demo)
{
    return out << demo.d_value;
}

using namespace std;

int main()
{
    using FBB::operator+;

    Demo four(4);
    Demo five(5);

    cout << four + five << '\n';
}


