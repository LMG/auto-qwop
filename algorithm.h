/**
 * @file algorithm.h
 * Contains functions related to the initialization (writing to a file) and
 * the execution of the generated scripts.
 */
#ifndef DEF_ALGORITHM_H
#define DEF_ALGORITHM_H

#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "constants.h"

/**
 * Generates a random algorithm and writes it to a file.
 * @param fp a pointer to a FILE to write it to.
 */
void randInit(FILE* fp);

/**
 * Runs an algorithm from a file.
 * @param fp a pointer to a FILE where the algorithm is.
 * @param display the display to execute the actions on.
 */
void run(FILE* fp, Display* display);

#endif
