#include "syslogstream.ih"

namespace 
{
    unordered_map<string, FBB::Facility> facilityMap =
    {
        {"AUTHPRIV",    FBB::AUTHPRIV},
        {"CRON",        FBB::CRON},
        {"DAEMON",      FBB::DAEMON},
        {"KERN",        FBB::KERN},
        {"LOCAL0",      FBB::LOCAL0},
        {"LOCAL1",      FBB::LOCAL1},
        {"LOCAL2",      FBB::LOCAL2},
        {"LOCAL3",      FBB::LOCAL3},
        {"LOCAL4",      FBB::LOCAL4},
        {"LOCAL5",      FBB::LOCAL5},
        {"LOCAL6",      FBB::LOCAL6},
        {"LOCAL7",      FBB::LOCAL7},
        {"LPR",         FBB::LPR},
        {"MAIL",        FBB::MAIL},
        {"NEWS",        FBB::NEWS},
        {"USER",        FBB::USER},
        {"UUCP",        FBB::UUCP},
    };
}

Facility SyslogStream::stoF(std::string const &name, Facility facility)
{
    auto iter = facilityMap.find(String::uc(name));
    return iter == facilityMap.end() ? facility : iter->second;
}
