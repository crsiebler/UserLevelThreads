// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 1
// Description: Write routines that perform standard queuing functions.
//		The functions work on multiple queues, and structure each queue as a doubly linked, circular list.

#include "q.h"

//-----------//
// t1 Method //
//-----------//
void t1() {
	// Create 10 Queue Elements
	// Print Queue
	int i;

	struct queue *head = (struct queue*) malloc(sizeof(struct queue));
	initQueue(head);

	for (i = 0; i < 10; i++) {
		struct q_elem *item = newItem();
		item->payload = i;
		addQueue(head, item);
	}

	printQueue(head);

	return;
}

//-----------//
// t2 Method //
//-----------//
void t2() {
	return;
}

//-------------//
// main Method //
//-------------//
int main() {
	t1();
	return 0;
}
