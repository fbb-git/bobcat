#include "cgi.ih"

size_t CGIFSA::tokenIdx()
{
    size_t token = (this->*s_tokenizer[d_state])(); // get the next token

    vector<Transition>::iterator ret =              // look it up
        find_if(s_fsa[d_state].begin(), s_fsa[d_state].end(), 
            FnWrap::unary(&hasToken, token));

    d_tokenIdx = ret - s_fsa[d_state].begin();      // determine the index
    if (d_tokenIdx == s_fsa[d_state].size())
        --d_tokenIdx;

    return d_tokenIdx;                              // return it
}
