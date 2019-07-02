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
} DataRow_s;

typedef struct {
StatementType type;
DataRow_s RowInsert;
} Statement_s;

typedef struct {
char* Buffer;
size_t BufferLength;
ssize_t InputLength;
} InputBuffer_s;

/* global variables */

/* function declarations */
InputBuffer_s* NewInputBuffer(void);
void CommandPrompt(void);
void ReadInput(InputBuffer_s* InBuffer);
void CloseInputBuffer(InputBuffer_s* InBuffer);
CommandResult RunCommand(InputBuffer_s* InBuffer);
PrepareResult PrepareStatement(InputBuffer_s* InBuffer, Statement_s* statement);
void ExecuteStatement(Statement_s* statement);
