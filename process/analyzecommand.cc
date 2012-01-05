#include "process.ih"

Process::ExecContext Process::analyzeCommand()
{
    string args(d_command);                 // First, analyze the arguments
     
    vector<String::SplitPair> elements;     // destination for the command's
                                            // elements,
    
    size_t count = String::split(&elements, args); // now extract the elements
    
                                            // set up a process struct
    ExecContext ec = {true, 0, 0, new char const *[count + 1]};

    for (auto &splitPair: elements)
        execContext(splitPair, ec);
    
    if (!ec.ok)
        throw Errno("Process ") << d_command << ": " << ec.message;
    
    if (!ec.argc)
        throw Errno("Process: can't execute ") << d_command;

    ec.args[ec.argc] = 0;
     
    return ec;
}





