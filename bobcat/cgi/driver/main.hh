#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include <bobcat/errno>
#include <bobcat/arg>
#include <bobcat/a2x>
#include <bobcat/cgi>

namespace Icmbuild
{
    extern char version[];
    extern char year[];
    extern char author[];
};

void usage(std::string const &progname);

using namespace std;
using namespace FBB;
using namespace Icmbuild;
