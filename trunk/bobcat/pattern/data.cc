#include "pattern.ih"

//    Note: all transitions of a state MUST be clustered
//          the last element of a cluster is the default transition.
//          its 0-value will be overwritten by the conversion.
//
PerlSetFSA::TransitionMatrix PerlSetFSA::s_stateTransitions[] =
{
    {Start,             '\\',   Bs,             &PerlSetFSA::nop    },
    {Start,             '\"',   DQuote,         &PerlSetFSA::copy   },
    {Start,             '\'',   Apostrophy,     &PerlSetFSA::copy   },
    {Start,             '[',    Set,            &PerlSetFSA::copy   },
    {Start,             0,      Start,          &PerlSetFSA::copy   },

    {Bs,                's',    Start,          &PerlSetFSA::s_Set  },
    {Bs,                'S',    Start,          &PerlSetFSA::S_Set  },
    {Bs,                'd',    Start,          &PerlSetFSA::d_Set  },
    {Bs,                'D',    Start,          &PerlSetFSA::D_Set  },
    {Bs,                'w',    Start,          &PerlSetFSA::w_Set  },
    {Bs,                'W',    Start,          &PerlSetFSA::W_Set  },
    {Bs,                '\\',   Start,          &PerlSetFSA::copy   },
    {Bs,                0,      Start,          &PerlSetFSA::copybs },

    {DQuote,            '\\',   DQuoteBs,       &PerlSetFSA::nop    },
    {DQuote,            '\"',   Start,          &PerlSetFSA::copy   },
    {DQuote,            0,      DQuote,         &PerlSetFSA::copy   },

    {DQuoteBs,          0,      DQuote,         &PerlSetFSA::copybs },
    
    {Apostrophy,        '\\',   ApostrophyBs,   &PerlSetFSA::nop    },
    {Apostrophy,        '\'',   Start,          &PerlSetFSA::copy   },
    {Apostrophy,        0,      Apostrophy,     &PerlSetFSA::copy   },

    {ApostrophyBs,      0,      Apostrophy,     &PerlSetFSA::copybs },

    {Set,               '^',    NotSet,         &PerlSetFSA::copy   },
    {Set,               '\\',   SetBs,          &PerlSetFSA::nop    },
    {Set,               '[',    SetNested,      &PerlSetFSA::copy   },
    {Set,               0,      InSet,          &PerlSetFSA::copy   },

    {NotSet,            '\\',   NotSetBs,       &PerlSetFSA::nop    },
    {NotSet,            '[',    NotSetNested,   &PerlSetFSA::copy   },
    {NotSet,            0,      InNotSet,       &PerlSetFSA::copy   },

    {NotSetBs,          's',    NotSet,         &PerlSetFSA::s_Nest },
    {NotSetBs,          'd',    NotSet,         &PerlSetFSA::d_Nest },
    {NotSetBs,          'w',    NotSet,         &PerlSetFSA::w_Nest },
    {NotSetBs,          '\\',   NotSet,         &PerlSetFSA::copy   },
    {NotSetBs,          ']',    Start,          &PerlSetFSA::copy   },
    {NotSetBs,          0,      NotSet,         &PerlSetFSA::copybs },

    {InNotSet,          ']',    Start,          &PerlSetFSA::copy   },
    {InNotSet,          '[',    NotSetNested,   &PerlSetFSA::copy   },
    {InNotSet,          0,      NotSetNested,   &PerlSetFSA::copy   },

    {NotSetNested,      ']',    InNotSet,       &PerlSetFSA::copy   },
    {NotSetNested,      0,      NotSetNested,   &PerlSetFSA::copy   },

    {InSet,             '[',    SetNested,      &PerlSetFSA::copy   },
    {InSet,             ']',    Start,          &PerlSetFSA::copy   },
    {InSet,             '\\',   SetBs,          &PerlSetFSA::nop    },
    {InSet,             0,      InSet,          &PerlSetFSA::copy   },

    {SetBs,             's',    InSet,          &PerlSetFSA::s_Nest },
    {SetBs,             'd',    InSet,          &PerlSetFSA::d_Nest },
    {SetBs,             'w',    InSet,          &PerlSetFSA::w_Nest },
    {SetBs,             '\\',   InSet,          &PerlSetFSA::copy   },
    {SetBs,             0,      InSet,          &PerlSetFSA::copybs },


    {SetNested,         ']',    InSet,          &PerlSetFSA::copy   },
    {SetNested,         0,      SetNested,      &PerlSetFSA::copy   },

};

PerlSetFSA::TransitionMatrix *PerlSetFSA::s_stateTransitions_end = 
    PerlSetFSA::s_stateTransitions +
        sizeof(PerlSetFSA::s_stateTransitions) 
        / 
        sizeof(PerlSetFSA::TransitionMatrix);

vector<PerlSetFSA::statePair> PerlSetFSA::s_transition;





