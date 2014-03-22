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
void f1() {
	while(1) {
		
	}
}

//-----------//
// f2 Method //
//-----------//
void f2() {
	while(1) {
		
	}
}

//-------------//
// main Method //
//-------------//
int main() {
	struct queue *readyQ = (struct queue*) malloc(sizeof(struct queue));
	initQueue(readyQ);

	startThread(f1());
	startThread(f2());
	run();

	return 0;
}
