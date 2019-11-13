#include <iostream>
#include "rawmode.h"
class inputsInterfce
{
    public:
    virtual void print(char c)=0;
    virtual ~inputsInterfce(){};
};
class controles:public inputsInterfce
{   public:
    void print(char c){printf("%d\r\n",c);}
};

class chars:public inputsInterfce{
    public:
    void print(char c){
      printf("%d ('%c')\r\n",c,c);
    }
};

class exits:public inputsInterfce{
    public:
    void print(char c){
      printf("%d:exiting by the user...",c);
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
        void printInput(char c){
            input->print(c);
        }
        
};
int main()
{
struct termios old_termios_settings;
term::enableRawMode(&old_termios_settings);
inputsFactory * ipFactory;  
while (1){
    char c = '\0';
    read(STDIN_FILENO, &c, 1);
    ipFactory = new inputsFactory(c);
    ipFactory->printInput(c);
    delete ipFactory;
} 
term::disableRawMode(&old_termios_settings);  
return 0;
}
