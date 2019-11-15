#ifndef __INPUTS_H__
#define __INPUTS_H__
#include "defs.h"
#include <unistd.h>
#include <iostream>

#ifdef __cplusplus
extern "C" {
namespace inputs{
#endif
class inputsInterfce
{
    public:
    virtual int print(char c)=0;
    virtual ~inputsInterfce();
};
class controlesInputClass:public inputsInterfce
{   public:
    int print(char c);
};

class charsInputClass:public inputsInterfce{
    public:
    int print(char c);
};

class exitsInputClass:public inputsInterfce{
    public:
    int print(char c);
};
class inputsFactory
{
    private:
        inputsInterfce * input=0;
    public:
        inputsFactory(char c);
        ~inputsFactory();
        int printInput(char c);
        
};



#ifdef __cplusplus
}}
#endif
#endif