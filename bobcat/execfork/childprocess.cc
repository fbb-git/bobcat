#include "execfork.ih"

void ExecFork::childProcess()
{
    vector<string> words = splitSource();

    execv(words[0].c_str(), 
            const_cast<char *const *>(String::argv(words)));

    throw Exception{} << "childprocess `" << d_cmd << "' failed";
}
