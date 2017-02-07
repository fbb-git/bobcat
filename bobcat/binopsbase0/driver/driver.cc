#include "../binopsbase"
//#include <bobcat/binopsbase>

#include <iostream>
using namespace std;

class Demo1: public FBB::BinopsBase<Demo1, 'i', '+', '-', '%'>
{
    friend FBB::BinopsBase<Demo1, 'i', '+', '-', '%'>;

    public:
        void swap(Demo1 &other)
        {}

    private:
        void add(Demo1 const &rhs)
        {
            cout << "adding two Demo1 objects\n";
        }

        void sub(Demo1 const &rhs)
        {
            cout << "subtracting two Demo1 objects\n";
        }

        void insert(ostream &out) const
        {
            out << "inserting a Demo1 object";
        }
};


class Demo2: public FBB::BinopsBase<Demo2, '+', '^'>
{
    friend FBB::BinopsBase<Demo2, '+', '^'>;

    public:
        void swap(Demo2 &other)
        {}

    private:
        void add(Demo2 const &rhs)
        {
            cout << "adding two Demo2 objects\n";
        }

        void xor_(Demo2 const &rhs)
        {
            cout << "xor-ing two Demo2 objects\n";
        }
};

int main()
{
    Demo1 d1a, d1b;
    Demo1 d1c = d1a + d1b;
    d1a += d1b;
    d1c = Demo1{} + d1b;

    cout << d1a << '\n';

    Demo2 d2a, d2b;
    Demo2 d2c = d2a + d2b;
    d2a ^= d2b;
    d2c = Demo2{} ^ d2b;
}






