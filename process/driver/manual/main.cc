#include "main.ih"

int main(int argc, char **argv)
try
{
    cout << "Enter for sha1sum\n";
    if (getline(cin, line))
    {
// start.cc
        newPipes();
        
    // forking.cc

        if ((pid = fork()) < 0)
            return 1;
    
        if (pid == 0)                       // child
        {
            redirectChild();
            childSha1();
        }
    
        parentRedirections();
        parentCloseIn();
    
        finalization();
    }

    cout << "Enter for manual cat\n";
    if (getline(cin, line))
    {
        try
        {
            while (true)
            {
                newPipes();
                
                if ((pid = fork()) < 0)
                    return 1;
            
                if (pid == 0)                       // child
                {
                    redirectChild();
        
                    childEchoes();
        
                    return 0;
                }    
        
                parentRedirections();
                parentCat();
        
        
                finalization();
            }
        }
        catch (bool)
        {}
    }

    cout << "Enter for ls-list\n";
    if (getline(cin, line))
    {
        newPipes();
        
        if ((pid = fork()) < 0)
            return 1;
    
        if (pid == 0)                       // child
        {
            redirectChild();
            childLs();
        }
    
        parentRedirections();
        parentOut();
    
        finalization();
    }


    return 0;
}
catch (...)
{
    return 1;
}
















