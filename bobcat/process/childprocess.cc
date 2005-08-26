#include "process.ih"

void Process::childProcess()
{
    if (d_processType == SYSTEM)        // execute using ::system() if
        exit(::system(str().c_str()));  // requested so

                                // No system, so run execl() or execle()

    String args(str());         // First, analyze the arguments
    
    vector<String::SplitPair> elements;     // destination for the command's
                                            // elements,

    unsigned count = args.split(&elements); // now extract the elements

                                            // set up a process struct
    ExecContext ec = {true, 0, 0, new char const *[count + 1]};

    for_each(elements.begin(), elements.end(), 
                Wrap1c<String::SplitPair, ExecContext>
                    (&Process::execContext, ec));

    if (!ec.ok)
    {
        std::cerr << "Process::execute(): " << ec.message << endl;
        exit(-1); 
    }    

    if (!ec.argc)
    {
        std::cerr << "Process::execute(): missing program to execute" << endl;
        exit(-1); 
    }    

    ec.args[ec.argc] = 0;
    (d_processType == EXECV ? execv : execvp)
        (
            ec.args[0], 
            const_cast<char * const *>(ec.args)
        );

    std::cerr << "Process::execute(): exec() failed" << endl;
    exit(-1); 
}
