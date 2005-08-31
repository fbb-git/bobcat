#ifndef _INCLUDED_HANDLER_
#define _INCLUDED_HANDLER_

#include <bobcat/fork>

class Handler: public FBB::Fork
{
    unsigned d_descriptor;
    public:
        Handler(unsigned descriptor)
        :
            d_descriptor(descriptor)
        {}

    private:
        virtual void childProcess();
        virtual void parentProcess()
        {
            close (d_descriptor);
        }
};

        
#endif
