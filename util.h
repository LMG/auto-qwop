/**
 * @file util.h
 * Various useful fonctions.
 */
 
#ifndef DEF_UTIL_H
#define DEF_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "constants.h"

/**
 * Open files named generation<currentGen>_<script>
 * @param fp: matrix (nbGens x nbScripts) of file pointers.
 * @param currentGen: Current generation to open
 * @param nbScripts: number of scripts to open
 */
void openFiles(FILE* fp[][NB_SCRIPTS], int currentGen, int nbScripts);

/**
 * Delays the start by delay seconds.
 * @param delay: number of seconds.
 */
void delayed_start(int delay);

#endif
