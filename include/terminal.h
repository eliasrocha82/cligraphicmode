#ifndef __TERMINAL_H__
#define __TERMINAL_H__
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "inputs.h"
#ifdef __cplusplus
extern "C" {
namespace terminal{
#endif
    class terminalClass
    {
        private:
            termios m_oldTermios;
            termios m_currentTermios;
            termios * m_currentTermiosPtr;
        public:
            int init();
            int exit();
            static char readKey();
            int processInput();
            static int drawRows();
            static int refresh();
            int processKeys();

    };
#ifdef __cplusplus
}}
#endif
#endif