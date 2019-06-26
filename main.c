/*
Relational Database with Command Line
	-functions similar to sql lite interface

Travis Hermant, Ryan Bornhorst
*/

/* includes */
#include "REPL/repl.h"

int main(int argc, char* argv[]) {

	/* local variables */
	InputBuffer_s* InBuffer;

	/* initialize variables */
	InBuffer = NewInputBuffer();

	/* run database command prompt */
	while(true) {

		// print db prompt
		CommandPrompt();
	
		// grab input
		ReadInput(InBuffer);

		// check for valid command
		if(InBuffer -> Buffer[0] == '.') {
			switch(RunCommand(InBuffer)) {
				case(COMMAND_SUCCESS):
					continue;
				case(COMMAND_FAILURE):
					printf("Command Not Valid '%s'\n", 
						InBuffer -> Buffer);
					continue;
			}
		}

		// check for valid statement
		Statement_s statement;
		switch(PrepareStatement(InBuffer, &statement)) {
			case(PREPARE_SUCCESS):
				break;
			case(PREPARE_FAILURE):
				printf("Keyword Not Valid for '%s'\n", 
					InBuffer -> Buffer);
				continue;
		}

		// execute the statement
		ExecuteStatement(&statement);
		printf("Statement Executed\n");
	}
}


