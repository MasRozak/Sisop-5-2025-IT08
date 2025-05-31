#ifndef __SHELL_H__
#define __SHELL_H__

#include "std_type.h"

void shell();
void parseCommand(char *buf, char *cmd, char arg[2][64]);
void printPrompt();

extern char username[64];
extern char grandcompany[16];
extern char color;

#endif // __SHELL_H__
