#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <bobcat/errno>
#include <bobcat/a2x>
#include <bobcat/arg>
#include <bobcat/msg>
#include <bobcat/ofoldstream>

namespace Icmbuild
{
    extern char version[];
    extern char year[];
    extern char author[];
};

void usage(std::string const &progname);
void header(std::ostream &out);
void lcBase(std::ostream &out, size_t nargs);
void typeList(std::ostream &out, size_t nTs, size_t nUnspec);
void typeDefList(std::ostream &out, size_t nTs);
void typeDefList(std::ostream &out, size_t nArgs, size_t nNoDefault, 
                                                  char const *defaultType);
void list(std::ostream &out, size_t nTs, char const *txt);
void listUnspec(std::ostream &out, size_t nUnspec);
void argList(std::ostream &out, size_t nTs);
void parList(std::ostream &out, size_t nTs);
void lcBaseCons(std::ostream &out, size_t nargs, size_t nArgsTotal);
void lcCons(std::ostream &out, size_t nargs, size_t argsTot);
void lc(std::ostream &out, size_t nargs);

using namespace Icmbuild;
using namespace std;
using namespace FBB;





