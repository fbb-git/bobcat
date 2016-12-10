#include "execfork.ih"

vector<string> ExecFork::splitSource() const
{
    String::Type type;
    return String::split(&type, d_cmd);
}
