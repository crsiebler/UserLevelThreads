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
int global = 0;

//--------------------//
// Threaded Functions //
//--------------------//

//-----------//
// f1 Method //
//-----------//
void f1(void) {
	int local = 0;

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
	int local = 0;

	while(1) {
		printf("THREAD 2:\tGLOBAL: %d\tLOCAL: %d\n", global, local);	
		global++;
		local++;
		sleep(1);
		yield();
	}
	
	return;
}

//-----------//
// f3 Method //
//-----------//
void f3(void) {
	int local = 0;
	
	while(1) {
		printf("THREAD 3:\tGLOBAL: %d\tLOCAL: %d\n", global, local);
		global++;
		local++;
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
