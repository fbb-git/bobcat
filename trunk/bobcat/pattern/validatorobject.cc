#include "pattern.ih"

void PerlSetFSA::Validator::operator()(TransitionMatrix const &state)
{
    static char name[] = "Pattern::PerlSetFSA::Validator()";

    d_element++;

    if (state.d_state != d_state)       // new state ?
    {
        if (d_last != 0)
            d_valid = false, 
            cerr << name << ", element #" << d_element << 
                    ": last transition of state " << d_state << " not 0\n";

        d_state = state.d_state;        // set new state;
        d_last = state.d_input;         // set new transition character

        if (d_used[d_state])
            d_valid = false, 
            cerr << name << ", element #" << d_element << 
                    ": Non-contiguous use of state " << d_state << endl;

        d_used[d_state] = true;
    }
}
