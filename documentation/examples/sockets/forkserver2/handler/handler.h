#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

#include <bobcat/fork>

class Handler: public FBB::Fork
{
    size_t d_descriptor;
    public:
        Handler(size_t descriptor)
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
