/**
 * @file constants.h
 * Constants used in projet.
 */

#ifndef DEF_CONSTANTS_H
#define DEF_CONSTANTS_H

/// The delay before start (in seconds).
#define DELAY 3
/// Max number of lines in a script.
#define MAXLINES 100
/// Max sleep during a script.
#define MAXSLEEP 3
/// Time given to a script to execute.
#define TIMEOUT 10
/// Number of scripts at each generation.
#define NB_SCRIPTS  3
/// Number of generations.
#define NB_GENS 10

/// Instructions in a script.
enum{QWOP, SLEEP, GOTO};
/// Available keys to press.
enum{Q, W, O, P};

#endif
