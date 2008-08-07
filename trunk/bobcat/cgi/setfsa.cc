#include "cgi.ih"

void CGIFSA::setFsa(Record const &record)
{
    Transition transition = {record.token, record.action, record.next};

    s_fsa[record.current].push_back(transition);

    if (record.token == DEFAULT)           // default contains ptr to tokenizer
        s_tokenizer[record.current] = record.tokenizer;
}
