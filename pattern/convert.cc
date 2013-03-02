#ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif
#ifndef _SYSINC_IOMANIP_
#include <iomanip>
#define _SYSINC_IOMANIP_
#endif

#include "pattern.ih"

void PerlSetFSA::convert(string &pattern)
{
    d_next = pattern.begin();

    d_target.clear();
    
    State state = Start;

//    cout << "Original: " << pattern << endl;

    for (   ; d_next != pattern.end(); d_next++)
    {
        int  current = *d_next;

//cout << "state: " << setw(2) << state << ", input: " << current <<
//      " (" << static_cast<char>(current) << ") " <<
//    " from: " <<  (s_transition[state].first - s_stateTransitions) <<
//    ", to: "  <<  (s_transition[state].second - s_stateTransitions) << endl;

                                    // set the current char in the transition
                                    // matrix
        s_transition[state].second->d_input = current;    

        TransitionMatrix *mp = s_transition[state].first;
        while (mp->d_input != current)
            mp++;           // find the appropriate state transition element

//cout << "next state: " << setw(2) << mp->d_next << endl;
        
        (this->*mp->d_action)();  // do the appropriate action
        
        state = mp->d_next;
    }
    pattern = d_target;

//    cout << "Converted: " << pattern << endl;
}
