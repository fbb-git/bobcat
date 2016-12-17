#include "exec.ih"

vector<string> Exec::splitSource() const
{
    String::Type type;
    return String::split(&type, d_cmd);
}
