#include "spawn.ih"

void Spawn::childProcess()
{

    vector<string> cmd(String::split(static_cast<String::Type *>(0), 
                                    d_command));

    char const **args = String::argv(cmd);
    
    execv(args[0], const_cast<char *const *>(args));

    throw 0;    // this should not be reached, but if so main properly ends.
}
