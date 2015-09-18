#include "argconfig"

#include <iostream>
#include <functional>
#include <algorithm>

#include <bobcat/string>
#include <bobcat/exception>
#include <bobcat/iuo>

namespace FBB
{

class ArgConfig__
{
                                            // find long options given short
                                            // option char
    std::unordered_map<int, std::string> d_longOption; 
        
    public:
        ArgConfig__(LongOption__ const *begin, LongOption__ const *const end);

        std::unordered_map<int, std::string>::const_iterator        
                                        find(int optChar) const;    // .i
        
        std::unordered_map<int, std::string>::const_iterator 
                                        findEnd() const;            // .i
};

#include "find.f"
#include "findend.f"

} // FBB

using namespace FBB;
using namespace std;

