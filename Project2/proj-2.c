// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: 

//---------------//
// Include Files //
//---------------//
#include "threads.h"

//--------------------//
// Threaded Functions //
//--------------------//

//-----------//
// f1 Method //
//-----------//
void f1(void) {
	while(1) {
		printf("THREAD 1\n");	
		yield();
	}
}

//-----------//
// f2 Method //
//-----------//
void f2(void) {
	while(1) {
		printf("THREAD 2\n");	
		yield();
	}
}

//-------------//
// main Method //
//-------------//
int main() {
	struct queue *readyQ = (struct queue*) malloc(sizeof(struct queue));
	struct queue *runQ = (struct queue*) malloc(sizeof(struct queue));
	initQueue(readyQ);

	startThread(f1);
	startThread(f2);
	run();

	return 0;
}
