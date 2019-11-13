#include <iostream>
#include "rawmode.h"
class inputsInterfce
{
    public:
    virtual int print(char c)=0;
    virtual ~inputsInterfce(){};
};
class controles:public inputsInterfce
{   public:
    int print(char c)
    {
        printf("%d\r\n",c);
        return c;
    }
};

class chars:public inputsInterfce{
    public:
    int print(char c)
    {
      printf("%d ('%c')\r\n",c,c);
      return c;
    }
};

class exits:public inputsInterfce{
    public:
    int print(char c){
      printf("%d:exiting by the user...\n",c);
      return 0;
    }
};
class inputsFactory
{
    private:
        inputsInterfce * input=0;
    public:
        inputsFactory(char c)
        {   
            if(iscntrl(c))
            {
                input = new controles();
                
            }else
            { 
                input=new chars();
                
            }
            if(c=='q')
            {
                input=new exits();
            }

        }
        virtual ~inputsFactory(){
           delete input;
        }
        int printInput(char c){
           return input->print(c);
        }
        
};
int main()
{int quit=1;
struct termios old_termios_settings;
term::enableRawMode(&old_termios_settings);
inputsFactory * ipFactory;  
while (quit){
    char c = '\0';
    read(STDIN_FILENO, &c, 1);
    ipFactory = new inputsFactory(c);
    quit=ipFactory->printInput(c);
    delete ipFactory;
} 
term::disableRawMode(&old_termios_settings);  
return 0;
}
