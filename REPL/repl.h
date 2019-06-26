/*
Relational Database
*/

/* includes */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defines */
#define USERNAME_SIZE 32
#define PASSWORD_SIZE 32

/* enumerations */
typedef enum {
COMMAND_SUCCESS,
COMMAND_FAILURE
} CommandResult;

typedef enum {
PREPARE_SUCCESS,
PREPARE_FAILURE
} PrepareResult;

typedef enum {
INSERT,
SELECT
} StatementType;

/* structs */
typedef struct {
char UserName[USERNAME_SIZE];
char PassWord[PASSWORD_SIZE];
} DataRow;

typedef struct {
StatementType type;
} Statement;

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
CommandResult RunCommand(InputBuffer* InBuffer);
PrepareResult PrepareStatement(InputBuffer* InBuffer, Statement* statement);
void ExecuteStatement(Statement* statement);
