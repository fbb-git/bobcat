#include "signal.ih"

// Text copied from stackoverflow:
//
// How to convert a signal call into the equivalent sigaction call?
// 
// Suppose you installed a signal handler for the alarm signal,
// 
// signal(SIGALRM, myhandler);
// 
// The equivalent sigaction code is:
// 
// struct sigaction sa; 
// sa.sa_handler = myhandler;
// sigemptyset(&sa.sa_mask);
// sa.sa_flags = 0; 
// sigaction(SIGALRM, &sa, NULL)
// 
// However, we typically may also set the mask and the flags field. The mask
// is a temporary signal mask used during the signal handler execution. The
// SA_RESTART flag will automatically restart some (but not all) system calls
// that otherwise would have returned early (with EINTR error). The latter
// means we can simplify the rest of code somewhat because a restart loop may
// no longer be required.
// 
// sigfillset(&sa.sa_mask);
// sa.sa_flags = SA_RESTART; /* Restart functions if  interrupted by handler */

void Signal::signal(int signum, sighandler_t handler)
{
    struct sigaction sa; 

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART; 

    sigaction(signum, &sa, 0);
}
