#ifndef __RAWMODE__H__
#define __RAWMODE__H__
#include <termios.h>
#include <unistd.h>
#ifdef __cplusplus
    extern "C" {
#endif
namespace term{
void saveUserTermiosSettings(termios * term);
void restoreUserTermiosSettings(const termios * oldTerm);
void switchFlagEcho(termios * term);
void switchFlagCanon(termios * term);
void switchFlagSign(termios * term);
void switchFlagXon(termios * term);
void switchFlagExten(termios * term);
void switchFlagCrnl(termios * term);
void enableRawMode(termios * backupTerm);
void disableRawMode(termios * oldTerm);
}
#ifdef __cplusplus
    }
#endif
#endif //__RAWMODE_H__