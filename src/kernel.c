#include "shell.h"
#include "kernel.h"

extern char color;

int main() {
    clearScreen();
    shell();
}

void printString(char *str) {
    int i = 0;
    int pos = 0;
    while (str[i] != '\0') {
        putInMemory(0xB800, pos, str[i]);
        putInMemory(0xB800, pos + 1, color);
        i++;
        pos += 2;
    }
}

void readString(char *buf) {
    int index = 0;
    char c;
    do {
        c = (char)interrupt(0x16, 0x0000, 0, 0, 0);
        
        if (c == 0x0D) {
            buf[index] = '\0';
            interrupt(0x10, 0x0E00 | '\r', 0, 0, 0); 
            interrupt(0x10, 0x0E00 | '\n', 0, 0, 0); 
            break;
        } else if (c == 0x08 && index > 0) {
            index--;
            interrupt(0x10, 0x0E00 | 0x08, 0, 0, 0);
            interrupt(0x10, 0x0E00 | ' ', 0, 0, 0);
            interrupt(0x10, 0x0E00 | 0x08, 0, 0, 0);
        } else if (c >= 0x20 && index < 127) {
            buf[index] = c;
            index++;
            interrupt(0x10, 0x0E00 | c, 0, 0, 0);
        }
    } while (true);
}

void clearScreen() {
    int i;
    for (i = 0; i < 80 * 25 * 2; i += 2) {
        putInMemory(0xB800, i, ' ');
        putInMemory(0xB800, i + 1, color);
    }
    interrupt(0x10, 0x0200, 0, 0, 0);
}

// removed C implementation of getBiosTick() to prevent multiple definition
