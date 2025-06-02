#include "../include/shell.h"
#include "../include/kernel.h"
#include "../include/std_lib.h"

char username[64] = "user";
char grandcompany[16] = "";
char color = 0x07; 

static char *random_responses[] = {"yo", "ts unami gng </3", "sygau"};

void shell() {
    char buf[128];
    char cmd[64];
    char arg[2][64];
    int random_index;

    printString("Welcome to EorzeOS!\r\n");
    while (true) {
        printPrompt();
        readString(buf);

        parseCommand(buf, cmd, arg);

        if (strcmp(cmd, "user") == true) {
            if (arg[0][0] == '\0') {
                strcpy(username, "user");
                printString("Username changed to user\n");
            } else {
                strcpy(username, arg[0]);
                printString("Username changed to ");
                printString(username);
                printString("\n");
            }
        } else if (strcmp(cmd, "grandcompany") == true) {
            if (strcmp(arg[0], "maelstrom") == true) {
                strcpy(grandcompany, "Storm");
                color = 0x04; // Merah
                clearScreen();
            } else if (strcmp(arg[0], "twinadder") == true) {
                strcpy(grandcompany, "Serpent");
                color = 0x0E; // Kuning
                clearScreen();
            } else if (strcmp(arg[0], "immortalflames") == true) {
                strcpy(grandcompany, "Flame");
                color = 0x01; // Biru
                clearScreen();
            } else {
                printString("Invalid Grand Company\n");
            }
        } else if (strcmp(cmd, "clear") == true) {
            strcpy(grandcompany, "");
            color = 0x07; // Putih
            clearScreen();
        } else if (strcmp(cmd, "add") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x + y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "sub") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x - y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "mul") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            result = x * y;
            itoa(result, result_str);
            printString(result_str);
            printString("\n");
        } else if (strcmp(cmd, "div") == true) {
            int x, y, result;
            char result_str[16];
            atoi(arg[0], &x);
            atoi(arg[1], &y);
            if (y == 0) {
                printString("Division by zero\n");
            } else {
                result = div(x, y);
                itoa(result, result_str);
                printString(result_str);
                printString("\n");
            }
        } else if (strcmp(cmd, "yogurt") == true) {
            random_index = imod(getBiosTick(), 3);
            printString(random_responses[random_index]);
            printString("\n");
        } else if (strcmp(cmd, "yo") == true) {
            printString("gurt\n");
        } else if (strcmp(cmd, "gurt") == true) {
            printString("yo\n");
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
printString("\r\n");
printString(username);
    if (grandcompany[0] != '\0') {
        printString("@");
        printString(grandcompany);
    }
    printString("> ");
}
