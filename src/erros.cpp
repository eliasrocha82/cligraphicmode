#include "erros.h"
namespace erros
{
    void raiseError(const char * erroString)
    {
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        perror(erroString);
        
        exit(1);
    }
}