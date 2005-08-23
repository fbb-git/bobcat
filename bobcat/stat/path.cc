#include "stat.ih"

string Stat::path()
{
    auto_ptr<char> buf(new char[PATH_MAX]);

    return !realpath(d_name.c_str(), buf.get()) ? "" : buf.get();
}
