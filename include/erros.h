#ifndef __ERROS__H__
#define __ERROS__H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __cplusplus
extern "C" {
#endif
namespace erros{
    void raiseError(const char * erroString);



}
#ifdef __cplusplus
}
#endif
#endif