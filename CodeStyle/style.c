/*
Coding Style Reference File
Travis Hermant, Ryan Bornhorst
*/

/* global variables */
int GlobalInt_g = 0;

/*
Name: function_style
Returns: int
Parameters: void
*/
int FunctionStyle(void) {

/* local variables */
int LocalInt;

/* initialize variables */
LocalInt = 0;

/* add global and local int */
LocalInt += GlobalInt_g;

return LocalInt;

}



