#include "argconfig.ih"

ArgConfig &ArgConfig::instance()
{
    if (!s_argconfig)
        throw Errno("ArgConfig::instance(): not yet initialized");

    return *s_argconfig;
}
