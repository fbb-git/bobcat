#include <iostream>

#include "../fswap"

using namespace FBB;

    // Demo class, members d_v3 and d_v4 cannot be memcpy-fast swapped
    //
class Demo
{
    size_t d_v1;
    size_t d_v2;
    std::string d_v3;
    std::string d_v4;
    size_t d_v5;

    public:
        Demo(size_t value = 0);
        void show(char const *msg);
        void swap(Demo &rhs);
};

Demo::Demo(size_t value)
:
    d_v1(value),
    d_v2(value + 1),
    d_v3(std::to_string(value + 2)),
    d_v4(std::to_string(value + 3)),
    d_v5(value + 4)
{}

    // fast-swap 2 objects, except for d_v3 and d_v4, which are
    // swapped by either std::swap or their own .swap() members
    //
void Demo::swap(Demo &rhs)
{
                        // This is OK, after commenting out the 
//  fswap(*this, rhs);  // string members

                        // specifying members that should be swapped
                        // using std::swap. These members MUST be
                        // specified in their class declaration order 
    fswap(*this, rhs, d_v3, d_v4);
//  fswap(*this, rhs, d_v4, d_v3);  // this won't work...

                            // same, explicitly requesting the
                            // swap-mode
//  fswap<SwapMode::SWAPMEMBER>(*this, rhs, d_v3, d_v4); 

                            // explicitly requesting another
                            // swap-mode
//  fswap<SwapMode::STDSWAP>(*this, rhs, d_v3, d_v4);

                            // default, starting at a begin-member
                            // NOTE: the example does NOT swap d_v1
//  fswap(&d_v2, *this, rhs, d_v3, d_v4);

                            // use fastswap, but start at the
                            // member d_v1 (use this for derived
                            // classes whose base class do not
                            // support fast swapping.
                            // Before using this example comment 
                            // out the class's std::string members
//  fswap(&d_v1, *this, rhs, d_v3);

                            // same, explicitly requesting the 
                            // swap method, swapping all 
//  fswap<SwapMode::SWAPMEMBER>(&d_v1, *this, rhs, d_v3, d_v4);

                            // explicitly requesting another
                            // swap-mode
//  fswap<SwapMode::STDSWAP>(&d_v1, *this, rhs, d_v3, d_v4);

                            // use stdswap by default, but not
                            // for d_v4, for which .swap() is
                            // used
//  fswap(&d_v1, *this, rhs, d_v3, swapmember(d_v4));

                             // same
//  fswap<SwapMode::STDSWAP>(&d_v1, *this, rhs, d_v3, 
//                                              swapmember(d_v4));

                             // explicitly requesting the already
                             // default swap method is OK
//  fswap(&d_v1, *this, rhs, swapmember(d_v3), stdswap(d_v4));

}

void Demo::show(char const *msg)
{
    std::cout << msg << ". " << d_v1 << 
                    ", " << d_v2 <<
                    ", " << d_v3 << 
                    ", " << d_v4 <<
                    ", " << d_v5 <<
                    '\n';
}

using namespace std;

int main()
{
    Demo d1(10);
    Demo d2(20);

    d1.show("This is d1:");
    d2.show("This is d2:");

    cout << "swapping...\n";
    d1.swap(d2);  


    d1.show("This is d1:");
    d2.show("This is d2:");

}


