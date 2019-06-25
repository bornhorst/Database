/*
Relational Database
*/

/* includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structs */
typedef struct {
char* Buffer;
size_t BufferLength;
ssize_t InputLength;
} InputBuffer;

/* global variables */

/* function declarations */
InputBuffer* NewInputBuffer(void);
void CommandPrompt(void);
void ReadInput(InputBuffer* InBuffer);
void CloseInputBuffer(InputBuffer* InBuffer);

