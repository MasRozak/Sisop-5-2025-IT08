#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

char username[64] = "user";
char grandcompany[16] = "";
char color = 0x07; 

void shell() {
  char buf[128];
  char cmd[64];
  char arg[2][64];
  char *random_responses[] = {"yo", "ts unami gng </3", "sygau"};
  int random_index;

  printString("Welcome to EorzeOS!\n");
  while (true) {
    printPrompt();
    readString(buf);

    parseCommand(buf, cmd, arg);

    if (strcmp(cmd, "user")) {
      if (arg[0][0] == '\0') {
        strcpy(username, "user");
        printString("Username changed to user\n");
      } else {
        strcpy(username, arg[0]);
        printString("Username changed to ");
        printString(username);
        printString("\n");
      }
    } else if (strcmp(cmd, "grandcompany")) {
      if (strcmp(arg[0], "maelstrom")) {
        strcpy(grandcompany, "Storm");
        color = 0x04;
        clearScreen();
      } else if (strcmp(arg[0], "twinadder")) {
        strcpy(grandcompany, "Serpent");
        color = 0x0E;
        clearScreen();
      } else if (strcmp(arg[0], "immortalflames")) {
        strcpy(grandcompany, "Flame");
        color = 0x01;
        clearScreen();
      } else {
        printString("Invalid Grand Company\n");
      }
    } else if (strcmp(cmd, "clear")) {
      strcpy(grandcompany, "");
      color = 0x07;
      clearScreen();
    } else if (strcmp(cmd, "add")) {
      int x, y, result;
      atoi(arg[0], &x);
      atoi(arg[1], &y);
      result = x + y;
      char result_str[16];
      itoa(result, result_str);
      printString(result_str);
      printString("\n");
    } else if (strcmp(cmd, "sub")) {
      int x, y, result;
      atoi(arg[0], &x);
      atoi(arg[1], &y);
      result = x - y;
      char result_str[16];
      itoa(result, result_str);
      printString(result_str);
      printString("\n");
    } else if (strcmp(cmd, "mul")) {
      int x, y, result;
      atoi(arg[0], &x);
      atoi(arg[1], &y);
      result = x * y;
      char result_str[16];
      itoa(result, result_str);
      printString(result_str);
      printString("\n");
    } else if (strcmp(cmd, "div")) {
      int x, y, result;
      atoi(arg[0], &x);
      atoi(arg[1], &y);
      if (y == 0) {
        printString("Division by zero\n");
      } else {
        result = div(x, y);
        char result_str[16];
        itoa(result, result_str);
        printString(result_str);
        printString("\n");
      }
    } else if (strcmp(cmd, "yogurt")) {
      random_index = mod(getBiosTick(), 3);
      printString(random_responses[random_index]);
      printString("\n");
    } else {
      printString(buf);
      printString("\n");
    }
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0, arg_idx = 0;
  clear((byte *)cmd, 64);
  clear((byte *)arg[0], 64);
  clear((byte *)arg[1], 64);

  while (buf[i] == ' ') i++;

  while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
    cmd[j] = buf[i];
    i++;
    j++;
  }
  cmd[j] = '\0';

  while (buf[i] == ' ') i++;

  j = 0;
  while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
    arg[0][j] = buf[i];
    i++;
    j++;
  }
  arg[0][j] = '\0';

  while (buf[i] == ' ') i++;

  j = 0;
  while (buf[i] != ' ' && buf[i] != '\0' && j < 63) {
    arg[1][j] = buf[i];
    i++;
    j++;
  }
  arg[1][j] = '\0';
}

void printPrompt() {
  printString(username);
  if (grandcompany[0] != '\0') {
    printString("@");
    printString(grandcompany);
  }
  printString("> ");
}
