#include "syslogstream.hh"

namespace 
{
    unordered_map<string, FBB::Priority> priorityMap =
    {
        {"EMERG",   FBB::EMERG},
        {"ALERT",   FBB::ALERT},
        {"CRIT",    FBB::CRIT},
        {"ERR",     FBB::ERR},
        {"WARNING", FBB::WARNING},
        {"NOTICE",  FBB::NOTICE},
        {"INFO",    FBB::INFO},
        {"DEBUG",   FBB::DEBUG},
  };
}

Priority SyslogStream::stoP(std::string const &name, Priority priority)
{
    auto iter = priorityMap.find(String::uc(name));
    return iter == priorityMap.end() ? priority : iter->second;
}
