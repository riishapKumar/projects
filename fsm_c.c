/* FILE: fsm_c.c
   DSCE: idestifies caracters
   Aurtor: Rishap kumar
*/

#include <stdio.h>
#include <ctype.h>

#define STATE_START   1
#define STATE_BUILD_NUM   2
#define STATE_NUMBER   3
#define STATE_IDENTIFIER   4
#define STATE_BUILD_ID   5
#define STATE_STOP   6
#define ERROR   7


int transition(int state, char c);

/*
 * program entry point.
 */
int main(int argc, char **argv) {
	int state = STATE_START;
	char c;

	/*
	 * Implementation of the algorithm described in the document
	 */
	do {
		if(state == STATE_IDENTIFIER) {
			printf(": Identifier\n");
			state = STATE_START;
		}
		else if(state == STATE_NUMBER) {
			printf(": Number\n");
			state = STATE_START;
		}

		scanf("%c", &c);
		if(! (isblank(c) || isalnum(c) || c == ';' || c == '_')) {
			state = ERROR;
			break;
		}

		state = transition(state, c);
		if( !isblank(c) && state != STATE_STOP) {
			printf("%c", c);
		}

	}while(state != ERROR && state != STATE_STOP);

	if (state == ERROR) {
		printf(": Invalid input\n");
		return 1;
	}

	return 0;
}


/**
 * Transition from one state to another depending on the input and the current state
 */
int transition(int state, char c) {
	if(state == STATE_START) {
		if(isblank(c)) {
			return STATE_START;
		}
		if(isdigit(c)) {
			return STATE_BUILD_NUM;
		}
		if(isalpha(c)) {
			return STATE_BUILD_ID;
		}
		if(c == ';') {
			return STATE_STOP;
		}
		/* if we reach this point we have an invalid input.
		 * According to the diagram the possible transitions from START will be
		 * start, build id, build num and stop.
		 */

	}

	if(state == STATE_BUILD_ID) {
		if(isalnum(c) || c == '_') {
			return STATE_BUILD_ID;
		}
		if(isblank(c)) {
			return STATE_IDENTIFIER;
		}
	}

	if(state == STATE_IDENTIFIER || STATE_NUMBER) {
		// nothing to do the function should not be called
		// with the state being STATE_NUMBER or STATE_IDENTIFER because
		// those two are terminal states for the token being processed.
	}

	if(state == STATE_BUILD_NUM) {
		if(isdigit(c)) {
			return STATE_BUILD_NUM;
		}
		if(isblank(c)) {
			return STATE_NUMBER;
		}
	}
	return ERROR;
}
