// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: Holds routines to start threads, yield, and run

#ifndef THREADS_H
#define THREADS_H

//---------------//
// Include Files //
//---------------//
#include "q.h"

//-----------------------------//
// Global Variable Declaration //
//-----------------------------//
struct queue *readyQ;
struct queue *runQ;

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void startThread(void (*function)(void));
void run();
void yield();

//---------------------//
// start_thread Method //
//---------------------//
void startThread(void (*function)(void)) {
	TCB_t *temp = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	void *stack = malloc(8192);
	init_TCB(temp, function, stack, 8192);
	addQueue(readyQ, temp);
	return;
}

//------------//
// run Method //
//------------//
void run() {

	//start the first thread
	ucontext_t from, to;
	ucontext_t parent;
	from = parent;
	getcontext(&parent);
	to = (runQ->header->context);
	swapcontext(&parent, &(runQ->header->context));
	return;
}

//--------------//
// yield Method //
//--------------//
void yield() {
	ucontext_t from, to;	
	from = runQ->header->context;
	rotQueue(runQ);
	to = runQ->header->context;
	swapcontext(&from, &to);

	// According to class notes 
	/*
	ucontext_t *from, *to;
	from = &(runQ->context);
	rotQueue(runQ);
	to = &(runQ->context);
	swapcontext(from, to);
	*/
	return;
}

#endif
