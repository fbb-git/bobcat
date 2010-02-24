#include "cgi.ih"

// Characters are retrieved from d_in by the tokenizer. They are stored on
// the stack by the tokenizers, and retrieved from the stack by the
// action functions. All characters are interpreted as unsigned chars, and
// pushed as size_t values

void CGIFSA::run()
try
{
    d_state = START;

    while (true)            // throws exception after processing all chars
    {
        (this->*s_fsa[d_state][tokenIdx()].action)();
        d_state =  s_fsa[d_state][d_tokenIdx].next;
    }

}
catch(Token end)
{
    acceptAll();
}



