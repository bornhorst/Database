/*
Relational Database
*/

/* includes */
#include "repl.h"

/* functions */

/*
Name: NewInputBuffer
Returns: InputBuffer_s*
Parameters: void
*/
InputBuffer_s* NewInputBuffer(void) {

	/* initialize variables */
	InputBuffer_s* InBuffer = malloc(sizeof(InputBuffer_s));
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
Parameters: InputBuffer_s*
*/
void ReadInput(InputBuffer_s* InBuffer) {

	/* local variables */
	ssize_t BytesRead;

	/* initialize variables */
	BytesRead = getline(&(InBuffer -> Buffer), &(InBuffer -> BufferLength), 
			    stdin);

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
Parameters: InputBuffer_s*
*/
void CloseInputBuffer(InputBuffer_s* InBuffer) {

	/* free memory */
	free(InBuffer -> Buffer);
	free(InBuffer);

}

/*
Name: RunCommand
Returns: CommandResult
Parameters: InputBuffer_s*
*/
CommandResult RunCommand(InputBuffer_s* InBuffer) {

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
Parameters: InputBuffer_s*, Statement_s*
*/
PrepareResult PrepareStatement(InputBuffer_s* InBuffer, Statement_s* statement) {

	// insert, only want to capture 'INSERT' here 
	if(strncmp(InBuffer -> Buffer, "insert", 6) == 0) {
		statement -> type = INSERT;
		int Args = sscanf(InBuffer -> Buffer, "insert %s %s",
			         (statement -> RowInsert.UserName, 
				  statement -> RowInsert.PassWord));
		if(Args < 3)
			return PREPARE_FAILURE;

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
Parameters: Statement_s*
*/
void ExecuteStatement(Statement_s* statement) {

	// check for appropriate statements
	switch(statement -> type) {
		case(INSERT):
			break;
		case(SELECT):
			break;
	}

}
