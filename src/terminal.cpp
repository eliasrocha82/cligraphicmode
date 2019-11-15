#include "terminal.h"
#ifdef __cplusplus
extern "C" {
namespace terminal{
#endif
int terminalClass::init(){
    int err;
    err=tcgetattr(STDIN_FILENO,&this->m_oldTermios);
    if(err==-1){
        throw "init(): getting termios attributes.";
    }
    this->m_currentTermios=m_oldTermios;
    this->m_currentTermiosPtr=&m_currentTermios;
    (*m_currentTermiosPtr).c_cc[VMIN]=0;
    (*m_currentTermiosPtr).c_cc[VTIME]=1;
    (*m_currentTermiosPtr).c_oflag &= ~(OPOST);
    (*m_currentTermiosPtr).c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    (*m_currentTermiosPtr).c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    (*m_currentTermiosPtr).c_cflag |=  (CS8);
    err=tcsetattr(STDIN_FILENO,TCSAFLUSH,&this->m_currentTermios);
    if(err==-1){
        throw "init(): setting termios attributes.";
    }
    return 0;    
}
char terminalClass::readKey() {
  int err;
  char c;
  while ((err = read(STDIN_FILENO, &c, 1)) != 1) {
    if (err == -1 && err != EAGAIN) throw "readKey(): readding STDIN_FILENO";
  }
  return c;
}
int terminalClass::processInput()
{
    int quit;
    char c = '\0';
    inputs::inputsFactory * ipFactory;
    //read(STDIN_FILENO, &c, 1);
    c=terminalClass::readKey();
    ipFactory = new inputs::inputsFactory(c);
    quit=ipFactory->printInput(c);
    delete ipFactory;
    return quit;
}
int terminalClass::drawRows()
{
    int y;
    for (y = 0; y < 24; y++)
    {
        write(STDOUT_FILENO, "|\r\n", 3);
    }
    return 0;
}
int terminalClass::refresh()
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    terminalClass::drawRows();
    write(STDOUT_FILENO, "\x1b[H", 3);
    return 0;
}
int terminalClass::exit()
{   int err;
    err=tcsetattr(STDIN_FILENO,TCSAFLUSH,&this->m_oldTermios);
    if(err==-1)
        throw "exit(): setting termios attributes.";
    return 0;
}




#ifdef __cplusplus
}}
#endif