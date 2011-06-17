#include <iostream>
#include <string>
#include "../typetrait"

using namespace std;
using namespace FBB;

template <typename T>
void show(char const *name)
{
    cout << "Type: " << name << boolalpha << ":\n"
            "   "
            "is pointer: "  << TypeTrait<T>::isPointer << ", "
            "is const: "    << TypeTrait<T>::isConst << ", "
            "is ref: "      << TypeTrait<T>::isRef << ", "
            "is r-ref: "    << TypeTrait<T>::isR_Ref << '\n';
}
    
int main()
{
    TypeTrait<int *>::Plain        int1 = 12;
    TypeTrait<int const *>::Plain  int2 = 12;
    TypeTrait<int &>::Plain        int3 = 12;
    TypeTrait<int const &>::Plain  int4 = 12;
    TypeTrait<int &&>::Plain       int5 = 12;
    TypeTrait<int const &&>::Plain int6 = 12;

    show<int>("int");   
    show<int *>("int *");   
    show<int const>("int const");   
    show<int const *>("int const *");   
    show<int &>("int &");   
    show<int const &>("int const &");   
    show<int &&>("int &&");   
    show<int const &&>("int const &&");   


    cout << "=======================\n";

    cout << "string promotes char const *: " << 
                LpromotesR<string, char const *>::yes << '\n';
    cout << "string promotes string " << 
                LpromotesR<string, string>::yes << '\n';
    cout << "char const * promotes string " << 
                LpromotesR<char const *, string>::yes << '\n';
}
