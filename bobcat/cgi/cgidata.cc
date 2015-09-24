#include "cgi.ih"

vector<string> CGI::s_empty;

bool CGIFSA::s_installed(false);

vector<CGIFSA::Transition> CGIFSA::s_fsa[N_STATES_];
size_t (CGIFSA::*CGIFSA::s_tokenizer[N_STATES_])();


    // a buffer is filled with the read character(s). push will push them 
    // L to R onto the charstack
    // accept will pop all characters and accept them, except for the last
    // char, that is pushed
    
CGIFSA::Record const CGIFSA::s_fsaRawData[] =
{
  // --------------------------------------------------------------------
  // cur. state  token      action             next state    tokenizer
  // --------------------------------------------------------------------
    {START,       '[',      &CGIFSA::push,      OPENBRACKET,  0},
    {START,       DEFAULT,  &CGIFSA::push,      CHECKSET,     &CGIFSA::charToken},
                                             
    {CHECKSET,    '-',      &CGIFSA::push,      DEFINESET,    0},
    {CHECKSET,    '[',      &CGIFSA::accept,    OPENBRACKET,  0},
    {CHECKSET,    DEFAULT,  &CGIFSA::accept,    CHECKSET,     &CGIFSA::charToken},
                                             
    {DEFINESET,   DEFAULT,  &CGIFSA::charRange, START,        &CGIFSA::charToken},
                                             
    {OPENBRACKET, '-',      &CGIFSA::push,      DEFINESET,    0},
    {OPENBRACKET, '[',      &CGIFSA::accept,    OPENBRACKET,  0},
    {OPENBRACKET, ':',      &CGIFSA::push,      LEFTCOLON,    0},
    {OPENBRACKET, DEFAULT,  &CGIFSA::accept,    CHECKSET,     &CGIFSA::charToken},
                                             
    {LEFTCOLON,   SET,      &CGIFSA::push,      SETNAME,      0},
    {LEFTCOLON,   '-',      &CGIFSA::push,      DEFINESET,    0},     
    {LEFTCOLON,   DEFAULT,  &CGIFSA::accept,    CHECKSET,     &CGIFSA::wordToken},
                                             
    {SETNAME,     ':',      &CGIFSA::push,      RIGHTCOLON,   0},
    {SETNAME,     DEFAULT,  &CGIFSA::accept,    CHECKSET,     &CGIFSA::charToken},

    {RIGHTCOLON,  ']',      &CGIFSA::charClass, START,        0},
    {RIGHTCOLON,  '-',      &CGIFSA::push,      DEFINESET,    0},
    {RIGHTCOLON,  DEFAULT,  &CGIFSA::accept,    CHECKSET,     &CGIFSA::charToken},
  // --------------------------------------------------------------------
};

CGIFSA::Record const *const CGIFSA::s_fsaRawDataEnd = 
                CGIFSA::s_fsaRawData +
                sizeof(CGIFSA::s_fsaRawData) / sizeof(CGIFSA::Record);
  
PairCPPFunP const CGIFSA::s_charClass[] = 
{
    PairCPPFunP("alnum",    &isalpha),
    PairCPPFunP("alpha",    &isalpha),
    PairCPPFunP("cntrl",    &iscntrl),
    PairCPPFunP("digit",    &isdigit),
    PairCPPFunP("graph",    &isgraph),
    PairCPPFunP("lower",    &islower),
    PairCPPFunP("print",    &isprint),
    PairCPPFunP("punct",    &ispunct),
    PairCPPFunP("space",    &isspace),
    PairCPPFunP("upper",    &isupper),
    PairCPPFunP("xdigit",   &isxdigit),
    PairCPPFunP("cgi",      &iscgi),        // extension to std char classes
};

string CGIFSA::s_cgi("\"'`;\\");

PairCPPFunP const *const CGIFSA::s_charClassEnd = 
        CGIFSA::s_charClass + 
        sizeof(CGIFSA::s_charClass) / sizeof(PairCPPFunP);

char const *CGIFSA::s_stateName[] =         // change when enum State changes
{
        "START",
        "CHECKSET",
        "DEFINESET",
        "OPENBRACKET",
        "LEFTCOLON",
        "SETNAME",
        "RIGHTCOLON",
        "STOP",
};

