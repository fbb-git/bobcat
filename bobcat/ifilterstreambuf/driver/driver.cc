#include <iostream>
#include <istream>
#include <string>

#include <bobcat/ifilterstreambuf>


class CharFilterStreambuf: public FBB::IFilterStreambuf
{
    std::istream &d_in;         // stream to read from
    std::string d_rmChars;      // chars to rm
    std::string d_buffer;       // locally buffered chars
    size_t const d_maxSize = 100;

    public:
        CharFilterStreambuf(std::istream &in, std::string const &rmChars);

    private:
        bool filter(char const **srcBegin, 
                    char const **srcEnd) override;
};

CharFilterStreambuf::CharFilterStreambuf(std::istream &in, 
                                         std::string const &rmChars)
:
    d_in(in),
    d_rmChars(rmChars)
{}

bool CharFilterStreambuf::filter(char const **srcBegin, 
                                 char const **srcEnd)
{
    d_buffer.clear();

    while (d_buffer.size() != d_maxSize)
    {
        char ch;
        if (not d_in.get(ch))
            break;
        if (d_rmChars.find(ch) != std::string::npos) // found char to rm
            continue;
        d_buffer.push_back(ch);
    }

    if (d_buffer.empty())
        return false;

    *srcBegin = d_buffer.data();    
    *srcEnd = d_buffer.data() + d_buffer.size();

    return true;
}

int main()
{
    CharFilterStreambuf buf1(std::cin, "1234567890");
    std::istream in1(&buf1);

    CharFilterStreambuf buf2(in1, "AEIOUaeiou");
    std::istream in2(&buf2);

    std::cout << in2.rdbuf();
}





