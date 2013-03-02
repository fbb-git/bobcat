#include "process.ih"

Process::ExecContext Process::analyzeCommand()
{
//    std::cerr << "Command: `" << d_command << "'" << endl;

    String args(d_command);                 // First, analyze the arguments
     
    vector<String::SplitPair> elements;     // destination for the command's
                                            // elements,
    
    size_t count = args.split(&elements); // now extract the elements
    
                                            // set up a process struct
    ExecContext ec = {true, 0, 0, new char const *[count + 1]};
    
    for_each(elements.begin(), elements.end(), 
                Wrap1c<String::SplitPair, ExecContext>
                    (&execContext, ec));
    
    if (!ec.ok)
    {
//     std::cerr << "Process::execute(): " << ec.message << endl;
        exit(-1); 
    }    
    
    if (!ec.argc)
    {
//     std::cerr << "Process::execute(): missing program to execute" << endl;
        exit(-1); 
    }    
    
//    std::cerr << "Process::execute(): executing `" << ec.args[0] << "'" << 
//                endl;
    
    ec.args[ec.argc] = 0;
     
    return ec;
}





