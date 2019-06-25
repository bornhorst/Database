/*
Relational Database with Command Line
	-functions similar to sql lite interface

Travis Hermant, Ryan Bornhorst
*/

/* includes */
#include "REPL/repl.h"

int main(int argc, char* argv[]) {

/* local variables */
InputBuffer* InBuffer;

/* initialize variables */
InBuffer = NewInputBuffer();

/* run database command prompt */
while(true) {

	// print db prompt
	CommandPrompt();
	
	// grab input
	ReadInput(InBuffer);

	// follow command with action
	if(strcmp(InBuffer -> Buffer, ".exit") == 0) {
		CloseInputBuffer(InBuffer);
		exit(EXIT_SUCCESS);
	} else {
		printf("Not a valid command '%s'.\n", InBuffer -> Buffer);
	}
}

}


