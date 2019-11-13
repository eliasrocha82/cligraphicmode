#include "rawmode.h"
namespace term
{
    void saveUserTermiosSettings(termios * term)
    {
    tcgetattr(STDIN_FILENO,term);
    }
    void restoreUserTermiosSettings(const termios * oldTerm)
    {
        tcsetattr(STDIN_FILENO,TCSAFLUSH, oldTerm);
    }
    void switchTermiosOutputFlag(int flag)
    {
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_oflag = term.c_oflag & ~(flag);
        tcsetattr(STDIN_FILENO,TCSAFLUSH, &term);
    }
    void switchTermiosLocalFlag(int flag)
    {
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag = term.c_lflag & ~(flag);
        tcsetattr(STDIN_FILENO,TCSAFLUSH, &term);
    }
    void switchTermiosInputFlag(int flag)
    {
        termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_iflag = term.c_iflag & ~(flag);
        tcsetattr(STDIN_FILENO,TCSAFLUSH, &term);
    }
    void setTermiosTime(int newTime)
    {
        termios term;
        tcgetattr(STDIN_FILENO,&term);
        term.c_cc[VTIME]=newTime;
        tcsetattr(STDIN_FILENO,TCSAFLUSH,&term);
    }
    void setTermiosMin(int newMin)
    {
        termios term;
        tcgetattr(STDIN_FILENO,&term);
        term.c_cc[VMIN]=newMin;
    }
    void enableRawMode(termios * backupTerm)
    {
        term::saveUserTermiosSettings(backupTerm);
        term::switchTermiosLocalFlag(ECHO | ICANON | IEXTEN | ISIG);
        term::switchTermiosInputFlag(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        term::switchTermiosOutputFlag(OPOST); 
        term::setTermiosMin(0);
        term::setTermiosTime(1);   
    }

    void disableRawMode(termios * oldTerm)
    {
        term::restoreUserTermiosSettings(oldTerm);
    }
}