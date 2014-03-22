// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: 

//---------------//
// Include Files //
//---------------//
#include "threads.h"

//------------------//
// Global Variables //
//------------------//

//--------------------//
// Threaded Functions //
//--------------------//

//-----------//
// f1 Method //
//-----------//
void f1(void) {
	int local = 0;

	while(1) {
		printf("THREAD 1\n");	
		yield();
	}
}

//-----------//
// f2 Method //
//-----------//
void f2(void) {
	int local = 0;

	while(1) {
		printf("THREAD 2\n");	
		yield();
	}
}

//-------------//
// main Method //
//-------------//
int main() {
	runQ = (struct queue*) malloc(sizeof(struct queue));

	initQueue(runQ);

	startThread(f1);
	startThread(f2);
	run();

	return 0;
}
