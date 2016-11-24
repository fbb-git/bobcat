#ifndef INCLUDED_HANDLER_
#define INCLUDED_HANDLER_

#include <unistd.h>
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
        void childProcess() override;
        void parentProcess() override
        {
            close(d_descriptor);
        }
};

        
#endif
