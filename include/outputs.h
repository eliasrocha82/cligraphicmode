#ifndef __OUTPUTS__H__
#define __OUTPUTS__H__
#include <unistd.h>
#include <stdio.h>
#include <iostream>

#ifdef __cplusplus
extern "C" 
{
    namespace outputs
    {
#endif
    int editorDrawRows();
    int editorRefreshScreen(); 
#ifdef __cplusplus
    }
}
#endif
#endif