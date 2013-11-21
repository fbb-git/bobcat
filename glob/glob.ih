#include "glob"

#include <cstdlib>
#include <algorithm>

#include <bobcat/fswap>
#include <bobcat/stat>
#include <bobcat/exception>

using namespace std;
using namespace FBB;

struct Glob::GlobShare
{
    glob_t      globStruct;
    size_t      users;
    size_t      gsType;
    char      **begin;
    char      **end;
    size_t      size;
};

#include "mbegin.f"
#include "mend.f"


