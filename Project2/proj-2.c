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
int global = 0; // Increment after each run

//--------------------//
// Threaded Functions //
//--------------------//

//-----------//
// f1 Method //
//-----------//
void f1(void) {
	// Simple Couter
	static int local = 0;

	while(1) {
		printf("THREAD 1:\tGLOBAL: %d\tLOCAL: %d\n", global, local);	
		global++;
		local++;
		sleep(1);
		yield();
	}

	return;
}

//-----------//
// f2 Method //
//-----------//
void f2(void) {
	// Simulate Power of 2
	static int local = 2;

	while(1) {
		printf("THREAD 2:\tGLOBAL: %d\tLOCAL: %d\n", global, local);	
		global++;
		local *= 2;
		sleep(1);
		yield();
	}
	
	return;
}

//-----------//
// f3 Method //
//-----------//
void f3(void) {
	// Multiples of 3
	static int local = 3;

	while(1) {
		printf("THREAD 3:\tGLOBAL: %d\tLOCAL: %d\n\n", global, local);
		global++;
		local += 3;
		sleep(1);
		yield();
	}

	return;
}

//-------------//
// main Method //
//-------------//
int main() {
	runQ = (struct queue*) malloc(sizeof(struct queue));

	initQueue(runQ);

	startThread(f1);
	startThread(f2);
	startThread(f3);
	run();

	return 0;
}
