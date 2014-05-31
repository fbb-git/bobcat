#include "sharedstreambuf.ih"

SharedCondition SharedStreambuf::createSharedCondition()
{
    auto sharedCondition(SharedCondition::create(d_memory));
    seekoff(sharedCondition.offset() + sharedCondition.width());
    return sharedCondition;
}
