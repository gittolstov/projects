#ifndef INPUTS_H
#define INPUTS_H

/*!
*	Used to get double numbers from input (terminal)
*	\param[out] n tries to write one double number from stdin into it
*	\return if no adequate number was received from stdin returns 0, otherwise 1
*/
int getInputNumber(double *n);
/*!
*	manages arguments of cmd
*	\param[in] argc amount of args
*	\param[in] argv args
*	\return 1 if -c else 0
*/
int handleTerminalFlags(int argc, char *argv[]);
#endif