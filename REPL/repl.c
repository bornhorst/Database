/*
Relational Database
*/

/* includes */
#include "repl.h"

/* functions */

/*
Name: NewInputBuffer
Returns: InputBuffer*
Parameters: void
*/
InputBuffer* NewInputBuffer(void) {

/* initialize variables */
InputBuffer* InBuffer = malloc(sizeof(InputBuffer));
InBuffer -> Buffer = NULL;
InBuffer -> BufferLength = 0;
InBuffer -> InputLength = 0;

return InBuffer;

}

/*
Name: CommandPrompt
Returns: void
Parameters: void
*/
void CommandPrompt() { printf("database > "); };

/*
Name: ReadInput
Returns: void
Parameters: InputBuffer*
*/
void ReadInput(InputBuffer* InBuffer) {

/* local variables */
ssize_t BytesRead;

/* initialize variables */
BytesRead = getline(&(InBuffer -> Buffer), &(InBuffer -> BufferLength), stdin);

/* exit on error */
if(BytesRead <= 0) {
	printf("Input Error\n");
	exit(EXIT_FAILURE);
}

/* ignore newline */
InBuffer -> InputLength = BytesRead - 1;
InBuffer -> Buffer[BytesRead - 1] = 0;

}

/*
Name: CloseInputBuffer
Returns: void
Parameters: InputBuffer*
*/
void CloseInputBuffer(InputBuffer* InBuffer) {

/* free memory */
free(InBuffer -> Buffer);
free(InBuffer);

}

/*
Name: RunCommand
Returns: CommandResult
Parameters: InputBuffer*
*/
CommandResult RunCommand(InputBuffer* InBuffer) {

// check for valid command
if(strcmp(InBuffer -> Buffer, ".exit") == 0) {
	CloseInputBuffer(InBuffer);
	exit(EXIT_SUCCESS);
} else 
	return COMMAND_FAILURE;

}

/*
Name: PrepareStatment
Returns: PrepareResult
Parameters: InputBuffer*, Statement*
*/
PrepareResult PrepareStatement(InputBuffer* InBuffer, Statement* statement) {

// insert 
if(strncmp(InBuffer -> Buffer, "insert", 6) == 0) {
	statement -> type = INSERT;
	return PREPARE_SUCCESS;
}

// select
if(strcmp(InBuffer -> Buffer, "select") == 0) {
	statement -> type = SELECT;
	return PREPARE_SUCCESS;
}

return PREPARE_FAILURE;

}

/*
Name: ExecuteStatement
Returns: void
Parameters: Statement*
*/
void ExecuteStatement(Statement* statement) {

// check for appropriate statements
switch(statement -> type) {
	case(INSERT):
		break;
	case(SELECT):
		break;
}

}
