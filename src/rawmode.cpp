#include "rawmode.h"


namespace term
{
    void saveUserTermiosSettings(termios * term)
    {
        if(tcgetattr(STDIN_FILENO,term)==-1)
            erros::raiseError("tcgetattr in saveUserTemiosSettings");
    }
    void restoreUserTermiosSettings(const termios * oldTerm)
    {
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH, oldTerm)==-1)
            erros::raiseError("tcsetattr in restoreUserTermiosSettings");
    }
    void switchTermiosOutputFlag(int flag)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO, &term)==-1)
            erros::raiseError("tcgetatt in switchTermiosOutputFlag");
        term.c_oflag = term.c_oflag & ~(flag);
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH, &term)==-1)
            erros::raiseError("tcsetatt in switchTermiosOutputFlag");
    }
    void switchTermiosLocalFlag(int flag)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO, &term)==-1)
            erros::raiseError("tcgetatt in switchTermiosLocalFlag");
        term.c_lflag = term.c_lflag & ~(flag);
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH, &term)==-1)
            erros::raiseError("tcsetatt in switchTermiosLocalFlag");
    }
    void switchTermiosInputFlag(int flag)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO, &term)==-1)
            erros::raiseError("tcgetatt in switchTermiosInputFlag");
        term.c_iflag = term.c_iflag & ~(flag);
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH, &term)==-1)
            erros::raiseError("tcsetatt in switchTermiosOutputFlag");
    }
    void switchTermiosCFlag(int flag)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO, &term)==-1)
            erros::raiseError("tcgetatt in switchTermiosCFlag");
        term.c_cflag = term.c_cflag | (flag);
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH, &term)==-1)
            erros::raiseError("tcsetatt in switchTermiosCFlag");;
    
    }
   
    void setTermiosTime(int newTime)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO,&term)==-1)
            erros::raiseError("tcgetatt in setTermiosTime");
        term.c_cc[VTIME]=newTime;
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&term)==-1)
            erros::raiseError("tcsetatt in setTermiosTime");
    }
    void setTermiosMin(int newMin)
    {
        termios term;
        if(tcgetattr(STDIN_FILENO,&term)==-1)
            erros::raiseError("tcgetatt in setTermiosMin");
        term.c_cc[VMIN]=newMin;
        if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&term)==-1)
            erros::raiseError("tcsetatt in setTermiosMin");

    }
    void enableRawMode(termios * backupTerm)
    {
        term::saveUserTermiosSettings(backupTerm);
        term::switchTermiosLocalFlag(ECHO | ICANON | IEXTEN | ISIG);
        term::switchTermiosInputFlag(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        term::switchTermiosCFlag(CS8);
        term::switchTermiosOutputFlag(OPOST); 
        term::setTermiosMin(0);
        term::setTermiosTime(1);   
    }

    void disableRawMode(termios * oldTerm)
    {
        term::restoreUserTermiosSettings(oldTerm);
    }
}