/**
 * @file input.h
 * Manage user inputs.
 */
 
#ifndef DEF_INPUT_H
#define DEF_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads N chars from the user.
 * @param string The string to save the input to.
 * @param nbChar Number of chars to read (string must be longer).
 */
void readString(char *string, int nbChar);

/**
 * Reads a number (int) from the user.
 * @param nbDigits Number of digits to read.
 * @return The value read.
 */
int readNumber(int nbDigits);

/**
 * Flush stdio.
 */
void flushBuffer();

#endif
