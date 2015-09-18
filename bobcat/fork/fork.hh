#include "fork"

#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/wait.h>

#include <cstdlib>
#include <string>

#include <bobcat/exception>

using namespace std;
using namespace FBB;


