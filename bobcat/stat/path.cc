#include "stat.ih"

// This is required for the hurd-i386 arch, which apparently 
// fails to implement the POSIX standard:

#ifndef PATH_MAX
#   ifdef MAXPATHLEN
#       define PATH_MAX	MAXPATHLEN
#   else
#       define PATH_MAX	2048
#   endif
#endif

string Stat::path()
{
    unique_ptr<char> buf(new char[PATH_MAX]);

    return !realpath(d_name.c_str(), buf.get()) ? "" : buf.get();
}
