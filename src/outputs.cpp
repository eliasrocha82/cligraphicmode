#include "outputs.h"
#ifdef __cplusplus
namespace outputs{
#endif 
int editorDrawRows() {
  int y;
    for (y = 0; y < 24; y++) {
    write(STDOUT_FILENO, "|\r\n", 3);
  }
  return 0;
}   
int editorRefreshScreen()
{   
    
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);


    outputs::editorDrawRows();
    write(STDOUT_FILENO, "\x1b[H", 3);

    return 0;
}
#ifdef __cplusplus
}
#endif