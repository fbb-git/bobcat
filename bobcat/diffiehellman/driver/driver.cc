#include <iostream>

int main()
try
{
    FBB::DiffieHellman dh;
}
catch (std::exception const &exc)
{
    std::cout << exc.what() << '\n';
}
