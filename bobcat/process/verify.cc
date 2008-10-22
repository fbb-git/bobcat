#include "process.ih"

bool Process::verify()
{
    return true;
//
//    static fstream null(0);
//
////std::cerr << "VERIFY: PID IN = " << d_child.pid << endl;
//
//    if (d_waiter.pid != 0)
//    {
//        int retWaiter = waitpid(d_waiter.pid, &d_waiter.ret, WNOHANG);
//
//        if (retWaiter == d_waiter.pid)
//        {
//            d_waiter.pid = 0;               // process has ended
//            discontinue(d_child);
//        }
//    }
//    else if (d_child.pid != 0)
//    {
//        int retChild = waitpid(d_child.pid, &d_child.ret, WNOHANG);
//
//        if (retChild == d_child.pid)
//        {
//            d_child.pid = 0;               // process has ended
//            discontinue(d_waiter);
//        }
//    }
//
//    if (d_child.pid == 0)
//        open(null, null);
//
////std::cerr << "VERIFY: PID OUT = " << d_child.pid << endl;
//        
//    return d_child.pid;
}

