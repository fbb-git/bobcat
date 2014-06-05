#include <sys/types.h>
#include <unistd.h>

#include <iostream>

#include "../signal"

class SignalDemo: public FBB::SignalHandler
{
    volatile size_t d_signal;
    volatile bool d_continue;
    pid_t d_pid;

    public:
        SignalDemo();
        void run();

    private:
        void signalHandler(size_t signum) override;
};

using namespace std;
using namespace FBB;

SignalDemo::SignalDemo()
:
    d_signal(0),
    d_continue(true),
    d_pid(getpid())
{}

void SignalDemo::run()
{
    while (d_continue)
    {
        cout << "Send a SIGINT or SIGTERM... to process " << d_pid << endl;
        sleep(1);
    }
    cout << "Ending `run' after receiving signal " << d_signal << endl;
}

void SignalDemo::signalHandler(size_t signal)
{
    if (signal == SIGINT)
        cout << "Process " << d_pid << " received SIGINT" << endl;
    else if (signal == SIGTERM)
    {
        cout << "Process " << d_pid << " received SIGTERM" << endl;
        d_signal = SIGTERM;
        d_continue = false;
    }
}

int main()
{
    SignalDemo signalDemo;

    Signal::instance().add(SIGINT, signalDemo);
    Signal::instance().add(SIGTERM, signalDemo);

    signalDemo.run();
}





