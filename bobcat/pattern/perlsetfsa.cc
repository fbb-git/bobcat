#include "pattern.ih"

void PerlSetFSA::initialize(TransitionMatrix &stateDescription)
{
    statePair*statePtr = &s_transition[stateDescription.d_state]; 

    if (!statePtr->first)
        *statePtr = statePair(&stateDescription, &stateDescription);
    else
       statePtr->second++;
}


PerlSetFSA::PerlSetFSA()
{
    if (!s_transition.size())
    {
//        for_each(s_stateTransitions, s_stateTransitions_end, Validator());

        s_transition.resize(nStates_);
        for_each(s_stateTransitions, s_stateTransitions_end, initialize);
    }
}
