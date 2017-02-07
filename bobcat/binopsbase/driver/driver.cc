#include <iostream>

#include "../binopsbase"

class Demo1: public FBB::BinopsBase<Demo1>
{
    friend FBB::BinopsBase<Demo1>;            // for insert/extract

    public:
        void swap(Demo1 &other)
        {}

        Demo1 &&operator+=(Demo1 const &rhs) &&
        {
            std::cout << "adding two Demo1 objects\n";
            return std::move(*this);
        }

//        Demo1 &operator+=(Demo1 const &rhs) &
//        {
//            std::cout << "adding (self-defined) two Demo1 objects\n";
//            return *this;
//        }

        Demo1 &&operator-=(Demo1 const &rhs) &&
        {
            std::cout << "subtracting two Demo1 objects\n";
            return std::move(*this);
        }

        Demo1 &&operator<<=(Demo1 const &rhs) &&
        {
            std::cout << "shiftleft on two Demo1 objects\n";
            return std::move(*this);
        }

        Demo1 &&operator<<=(size_t rhs) &&
        {
            std::cout << "shiftleft Demo1 object size_t bits\n";
            return std::move(*this);
        }

        void insert(std::ostream &out) const        // requires friend
        {
            out << "inerting a Demo1 object\n";
        }

        void extract(std::istream &in)              // requires friend
        {
            std::cout << "extracting a Demo1 object\n";
        }
};


class Demo2: public FBB::BinopsBase<Demo2>
{
    public:
        void swap(Demo2 &other)
        {}

        Demo2 &&operator+=(Demo2 const &rhs) &&
        {
            std::cout << "adding two Demo2 objects\n";
            return std::move(*this);
        }

        Demo2 &operator+=(Demo2 const &rhs) &
        {
            std::cout << "adding (self-defined) two Demo2 objects\n";
            return *this;
        }

        Demo2 &&operator^=(Demo2 const &rhs) &&
        {
            std::cout << "xor-ing two Demo2 objects\n";
            return std::move(*this);
        }

        Demo2 &&operator|=(Demo2 const &rhs) &&
        {
            std::cout << "or-ing two Demo2 objects\n";
            return std::move(*this);
        }

};

int main()
{
    Demo1 d1a, d1b;
    Demo1 d1c = d1a + d1b;
    d1a += d1b;
    d1c = Demo1{} + d1b;

    std::cout << "Here we are " << d1c << '\n';
    std::cin >> d1c;

    d1a <<= d1a;
    d1a <<= 5;
//
//    Demo2 d2a, d2b;
//    Demo2 d2c = d2a + d2b;
//    d2a ^= d2b;
//    d2c = Demo2{} ^ d2b;
//
//    d2c = d2c | d2b;
}






