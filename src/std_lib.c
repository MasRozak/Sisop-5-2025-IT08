#include "../include/std_lib.h" 
#include "../include/std_type.h"

int div(int a, int b) {
  int quotient = 0;
  int sign = 1;

  if (a < 0) {
    a = -a;
    sign = -sign;
  }
  if (b < 0) {
    b = -b;
    sign = -sign;
  }

  while (a >= b) {
    a -= b;
    quotient++;
  }

  return sign * quotient;
}

int imod(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a >= b) a -= b;
    return a;
}


bool strcmp(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) return false;
    i++;
  }
  return str1[i] == str2[i];
}

void strcpy(char *dst, char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
  int i;
  for (i = 0; i < size; i++) {
    buf[i] = 0;
  }
}

void atoi(char *str, int *num) {
  int result = 0;
  int sign = 1;
  int i = 0;

  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  while (str[i] != '\0') {
    result = result * 10 + (str[i] - '0');
    i++;
  }

  *num = sign * result;
}

void itoa(int num, char *str) {
  int i = 0;
  int sign = 0;
  int temp = num;

  if (num < 0) {
    sign = 1;
    num = -num;
  }

  do {
    str[i++] = imod(num, 10) + '0';   
    num = div(num, 10);             
  } while (num > 0);

  if (sign) {
    str[i++] = '-';
  }

  str[i] = '\0';

  // Reverse string
  {
    int start = 0;
    int end = i - 1;
    char c;
    while (start < end) {
      c = str[start];
      str[start] = str[end];
      str[end] = c;
      start++;
      end--;
    }
  }
}
