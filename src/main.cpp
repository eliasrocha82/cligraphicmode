#include <iostream>
#include <errno.h>
//#include "rawmode.h"
//#include "defs.h"
//#include "erros.h"
//#include "outputs.h"
//#include "inputs.h"
#include "terminal.h"

int main()
{
    int quit=1;
    terminal::terminalClass * term = new terminal::terminalClass();
    try{
    (*term).init();
    }catch(const char * msg){
        std::cerr << msg << std::endl;
    }
    while(quit){
        try{
        (*term).refresh();
        quit=(*term).processInput();
        }catch(const char * msg){
            std::cerr << msg << std::endl;
        }
    }
    try
    {
        (*term).exit();
    }catch(const char * msg){
        std::cerr << msg << std::endl;
    }
    delete term;
    return 0;
}
