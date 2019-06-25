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
