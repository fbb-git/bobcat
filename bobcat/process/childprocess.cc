#include "process.ih"

void Process::childProcess()
{
    ExecContext ec;
    if (d_processType != USE_SHELL)
        ec = analyzeCommand();     // No system, so run execl() or execle()
    else
    {
        ec.args = new char const *[4];
        ec.args[0] = "/bin/sh";
        ec.args[1] = "-c";
        ec.args[2] = d_command.c_str();
        ec.args[3] = 0;
    }

#ifdef BOBCAT_DIY_CLOEXEC_
    if (d_closedByChild != 0)
        close(d_closedByChild);
#endif
                          
    (*(d_processType == USE_PATH ? execvp : execv))
        (ec.args[0], const_cast<char * const *>(ec.args));

    throw Errno("Process: ") << " cannot execv[p] " << d_command;

}

//    std::cerr << "ChildProcess starts as:\n";
//    for (char const **cp = ec.args; *cp; ++cp)
//        std::cerr << "  " << *cp << endl;
//    std::cerr << "======================\n";







