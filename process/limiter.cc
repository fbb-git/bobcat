#include "process.ih"

void Process::limiter(Process *process)
{
    size_t &timeLimit = process->d_timeLimit;

    if (timeLimit == 0)                 // no timelimit: thread immediately 
        return;                         //               ends

    unique_lock<mutex> lock(process->d_data->d_mutex);   // get the lock

    volatile ChildAction &action = process->d_data->d_action;

    action = TIME_LIMIT;

            // when the child process ends, signalHandler is called, which
            // sets d_action to CHILD_ENDED, and notifies this function: 
            // the loop ends with CHILD_ENDED. Otherwise, the time limit is
            // reached and the wait_for ends with d_action == TIME_LIMIT
    while (action != CHILD_ENDED)   
    {
                                        // When the time limit is reached
                                        // the loop breaks, and d_action is
                                        // TIME_LIMIT. 
        if (process->d_data->d_condition.wait_for(
                lock, chrono::seconds(timeLimit)) == cv_status::timeout)
            break;
    }

    if (action == TIME_LIMIT)
        process->discontinue(process->d_child);
}

