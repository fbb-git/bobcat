#include "pattern.ih"

//    Note: all state transitions MUST be clustered per state
//          the last element of a state cluster is the default transition.
//          its 0-value will be overwritten by the conversion.
//
PerlSetFSA::TransitionMatrix PerlSetFSA::s_stateTransitions[] =
{
    {Start,             '\\',   Bs,                 &PerlSetFSA::nop    },
    {Start,             '[',    Set,                &PerlSetFSA::copy   },
    {Start,             0,      Start,              &PerlSetFSA::copy   },
                                                    
    {Bs,                'd',    Start,              &PerlSetFSA::d_Set  },
    {Bs,                's',    Start,              &PerlSetFSA::s_Set  },
    {Bs,                'w',    Start,              &PerlSetFSA::w_Set  },
    {Bs,                'D',    Start,              &PerlSetFSA::D_Set  },
    {Bs,                'S',    Start,              &PerlSetFSA::S_Set  },
    {Bs,                'W',    Start,              &PerlSetFSA::W_Set  },
    {Bs,                0,      Start,              &PerlSetFSA::copybs },

    {Set,               '^',    NegatedSet,         &PerlSetFSA::copy   },
    {Set,               '\\',   SetBs,              &PerlSetFSA::nop    },
    {Set,               '[',    NestedSet,          &PerlSetFSA::copy   },
    {Set,               0,      InsideASet,         &PerlSetFSA::copy   },

    {NegatedSet,        '\\',   NegatedSetBs,       &PerlSetFSA::nop    },
    {NegatedSet,        '[',    NegatedNestedSet,   &PerlSetFSA::copy   },
    {NegatedSet,        0,      InsideANegatedSet,  &PerlSetFSA::copy   },

    {NegatedSetBs,      'd',    NegatedSet,         &PerlSetFSA::d_Nest },
    {NegatedSetBs,      's',    NegatedSet,         &PerlSetFSA::s_Nest },
    {NegatedSetBs,      'w',    NegatedSet,         &PerlSetFSA::w_Nest },
    {NegatedSetBs,      '\\',   NegatedSet,         &PerlSetFSA::copy   },
    {NegatedSetBs,      ']',    Start,              &PerlSetFSA::copy   },
    {NegatedSetBs,      0,      NegatedSet,         &PerlSetFSA::copybs },

    {InsideANegatedSet, ']',    Start,              &PerlSetFSA::copy   },
    {InsideANegatedSet, '[',    NegatedNestedSet,   &PerlSetFSA::copy   },
    {InsideANegatedSet, '\\',   NegatedSetBs,       &PerlSetFSA::nop    },
    {InsideANegatedSet, 0,      NegatedNestedSet,   &PerlSetFSA::copy   },

    {NegatedNestedSet,  ']',    InsideANegatedSet,  &PerlSetFSA::copy   },
    {NegatedNestedSet,  0,      NegatedNestedSet,   &PerlSetFSA::copy   },

    {InsideASet,        '[',    NestedSet,          &PerlSetFSA::copy   },
    {InsideASet,        ']',    Start,              &PerlSetFSA::copy   },
    {InsideASet,        '\\',   SetBs,              &PerlSetFSA::nop    },
    {InsideASet,        0,      InsideASet,         &PerlSetFSA::copy   },

    {SetBs,             'd',    InsideASet,         &PerlSetFSA::d_Nest },
    {SetBs,             's',    InsideASet,         &PerlSetFSA::s_Nest },
    {SetBs,             'w',    InsideASet,         &PerlSetFSA::w_Nest },
    {SetBs,             '\\',   InsideASet,         &PerlSetFSA::copy   },
    {SetBs,             0,      InsideASet,         &PerlSetFSA::copybs },

    {NestedSet,         ']',    InsideASet,         &PerlSetFSA::copy   },
    {NestedSet,         0,      NestedSet,          &PerlSetFSA::copy   },
};

PerlSetFSA::TransitionMatrix *PerlSetFSA::s_stateTransitions_end = 
    PerlSetFSA::s_stateTransitions +
        sizeof(PerlSetFSA::s_stateTransitions) 
        / 
        sizeof(PerlSetFSA::TransitionMatrix);

vector<PerlSetFSA::statePair> PerlSetFSA::s_transition;

string Pattern::Regex::s_converted;
