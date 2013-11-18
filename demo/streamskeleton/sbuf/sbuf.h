#ifndef INCLUDED_SBUF_
#define INCLUDED_SBUF_

#include <ios>
#include <iostream>
#include <streambuf>

class SBuf: public std::streambuf
{
    char data[20];

    int lastmode = 0;

    public:
        SBuf()
        {}

    private:

        int pbackfail(int c) override
        {
            std::cout << "pbackfail(int c)\n";
            return 0;
        }

        std::streamsize showmanyc() override
        {
            std::cout << "showmanyc()\n";
            return 0;
        }

        int underflow() override
        {
            if (lastmode != std::ios::in)
                return EOF;

            std::cout << "underflow() returns 'x'\n";
            setg(data, data + 1, data + 20);
            return 'x';
        }

        std::streamsize xsgetn(char *buffer, std::streamsize n) override
        {
            if (lastmode != std::ios::in)
                return EOF;

            std::cout << "xsgetn returns " << n << '\n';
            return n;
        }      
  
        int overflow(int c) override      
        {
            if (lastmode != std::ios::out)
                return EOF;
            setp(data, data + 20);
            pbump(1);
            std::cout << "overflow(" << c << ")\n";
            return c;
        }

        std::streamsize xsputn(char const *buffer, std::streamsize n) override
        {
            if (lastmode != std::ios::in)
                return EOF;

            std::cout << "xsputn returns " << n << '\n';
            return n;
        }      
  
        std::streambuf *setbuf(char *buffer, std::streamsize n) override
        {
            std::cout << "setbuf(" << n << ")\n";
            return this;
        }

        pos_type seekoff(off_type offset, std::ios::seekdir way,
            std::ios::openmode mode = std::ios::in | std::ios::out) override
        {
            std::cout << "seekoff(" << offset << ", mode = ";
            if (mode & std::ios::in)
                std::cout << "ios::in";
            if (mode & std::ios::out)
                std::cout << "ios::out";
            if (mode & std::ios::app)
                std::cout << "ios::app";
            std::cout <<  ")\n";
            return offset;
        }

        pos_type seekpos(pos_type offset, std::ios::openmode mode =
                              std::ios::in | std::ios::out) override
        {
            std::cout << "seekpos(" << offset << ", ";
            if (mode & std::ios::in)
                std::cout << "ios::in";
            if (mode & std::ios::out)
                std::cout << "ios::out";
            if (mode & std::ios::app)
                std::cout << "ios::app";
            std::cout <<  ")\n";

            lastmode = mode;

            return offset;
        }

        int sync() override
        {
            std::cout << "sync()\n";
            return 0;
        }
       
};
        
#endif
