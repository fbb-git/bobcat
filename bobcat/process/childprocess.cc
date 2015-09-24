#include "process.ih"

void Process::childProcess()
{
    ExecContext ec;
    if (d_processType != USE_SHELL)
        ec = analyzeCommand();     // No system, so run execl() or execle()
    else
    {
        ec.argv = new char const *[4];
        ec.argv[0] = "/bin/sh";
        ec.argv[1] = "-c";
        ec.argv[2] = d_command.c_str();
        ec.argv[3] = 0;
    }

#ifdef BOBCAT_DIY_CLOEXEC_
    if (d_closedByChild != 0)
        close(d_closedByChild);
#endif
                          
    (*(d_processType == USE_PATH ? execvp : execv))
        (ec.argv[0], const_cast<char * const *>(ec.argv));

    throw Exception() << "Process: cannot execv[p] " << d_command;

}

//    std::cerr << "ChildOutput starts as:\n";
//    for (char const **cp = ec.argv; *cp; ++cp)
//        std::cerr << "  " << *cp << endl;
//    std::cerr << "======================\n";







