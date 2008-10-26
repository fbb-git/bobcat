#include "process.ih"

Process::ExecContext Process::analyzeCommand()
{
    string args(d_command);                 // First, analyze the arguments
     
    vector<String::SplitPair> elements;     // destination for the command's
                                            // elements,
    
    size_t count = String::split(&elements, args); // now extract the elements
    
                                            // set up a process struct
    ExecContext ec = {true, 0, 0, new char const *[count + 1]};
    
    for_each(elements.begin(), elements.end(), 
                FnWrap1c<String::SplitPair const &, ExecContext &>
                    (&execContext, ec));
    
    if (!ec.ok)
        throw Errno("Process ") << insertable << d_command << ": " << 
                                                ec.message << throwable;
    
    if (!ec.argc)
        throw Errno("Process: can't execute ") << insertable << d_command <<
                                                                    throwable;
    ec.args[ec.argc] = 0;
     
    return ec;
}





