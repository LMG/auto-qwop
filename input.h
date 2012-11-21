#ifndef DEF_INPUT_H
#define DEF_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//reads N chars from the user
void readString(char *string, int nbChar);

int readNumber(int nbDigits);

void flushBuffer();

#endif
