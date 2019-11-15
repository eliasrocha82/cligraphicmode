#include "inputs.h"
#ifdef __cplusplus
extern "C" {
namespace inputs{
#endif
inputsInterfce::~inputsInterfce(){};

int controlesInputClass::print(char c)
{
    // printf("%d\r\n",c);
    return c;
}
int charsInputClass::print(char c)
{
    // printf("%d ('%c')\r\n",c,c);
    return c;
}

int exitsInputClass::print(char c)
{
    std::cout << c << ":exiting by the user...\r\n";
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    return 0;
}
inputsFactory::inputsFactory(char c)
        {   
            if(iscntrl(c))
            {
                input = new controlesInputClass();
            }else
            { 
                input=new charsInputClass();
            }
            if(c==CTRL_KEY('c'))
            {
                input=new exitsInputClass();
            }
        }
inputsFactory::~inputsFactory()
{
           delete input;
}
int inputsFactory::printInput(char c)
{
    return input->print(c);
}
        


#ifdef __cplusplus
}}
#endif