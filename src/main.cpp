#include <iostream>
#include <errno.h>
#include "rawmode.h"
#include "defs.h"
#include "erros.h"
#include "outputs.h"
#include "inputs.h"
#include "terminal.h"

int main()
{/*
    int quit=1;
    struct editorConfig {
        struct termios old_termios;
    };
    struct editorConfig E;

    term::enableRawMode(&E.old_termios);

    while (quit){
        outputs::editorRefreshScreen();
        quit=processKeys();
    } 
    term::disableRawMode(&E.old_termios); 
   */
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
    return 0;
}
