#include "process.ih"

void Process::childProcess()
{
    if (d_processType == USE_SHELL)
        exit(::system(d_command.c_str()));  

                                   // No system, so run execl() or execle()
    ExecContext ec = analyzeCommand();

    (*(d_processType == NO_PATH ? execv : execvp))
        (ec.args[0], const_cast<char * const *>(ec.args));

    exit(-1); 
}
