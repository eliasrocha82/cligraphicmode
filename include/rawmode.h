#ifndef __RAWMODE__H__
#define __RAWMODE__H__
#include <termios.h>
#include <unistd.h>
#include "erros.h"
#ifdef __cplusplus
    extern "C" {
#endif
namespace term{
void saveUserTermiosSettings(termios * term);
void restoreUserTermiosSettings(const termios * oldTerm);
void switchOutputFlag(termios * term);
void switchInputFlag(termios * term);
void switchCFlag(termios * term);
void setTermiosMin(int newMin);
void setTermiosTime(int newTime);
void switchTermiosCFlag(int flag);
void enableRawMode(termios * backupTerm);
void disableRawMode(termios * oldTerm);
}
#ifdef __cplusplus
    }
#endif
#endif //__RAWMODE_H__