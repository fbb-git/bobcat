#include "processdata.ih"

bool ProcessData::parentProcess(size_t timeLimit)
{
    if (timeLimit == 0)             // no wait, return true
        return true;

    d_action = PASSIVE;

    unique_lock<mutex> lock(d_mutex);   // get the lock

    while (d_action != CHILD_ENDED)
    {
        d_action = MONITORING;
        if (d_condition.wait_for(
                lock, chrono::seconds(timeLimit)) == cv_status::timeout)
            break;
    }

    return false;
}








