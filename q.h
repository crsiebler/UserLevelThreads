// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 1
// Description: Stores routines to initialize, add, rotate, and delete queues.
//		Also has function to create a new element in the queue and to free deleted elements.

#ifndef Q_H
#define Q_H

#include <stdio.h>

//----------------------------//
// Data Structure Declaration //
//----------------------------//
typedef struct q_elem {
	struct q_elem *prev;
	struct q_elem *next;
	int payload;
} q_elem;

typedef struct queue {
	struct q_elem *header;
} queue;

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void initQueue(struct queue);	// creates an empty queue, pointed to by the variable head
void addQueue(struct queue, struct q_elem);	// adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(struct queue);	// Moves the header pointer to the next element in the queue
struct q_elem* delQueue(struct queue);	// deletes an item from head and returns a pointer to the deleted item
struct q_elem* newItem();	// returns a pointer to a new q-element

//-------------------//
// Routine Functions //
//-------------------//
void initQueue(struct queue &head) {
	// Allocate space for new Queue
	head = (struct queue*) malloc(sizeof(struct queue));
	head.header = NULL;
	
	return;
}

void addQueue(struct queue &head, struct q_elem item) {
	item.prev = head.header.prev; // Add new link at end of chain
	item.next = head.header; // Attach new link to beginning of chain
	head.header.prev.next = item; // Make link from last element
	head.header.prev = item; // Make link to end from head
	
	return;
}

void rotateQ(struct queue &head) {
	// Move head pointer to next Element
	// Put first element at end of Queue
	addQueue(&head, delQueue(&head));
	
	return;
}

struct q_elem* delQueue(struct queue &head) {
	// Grab the first element in the Queue
	struct q_elem *item = head.header;

	// Grab the last element and next element
	// Assign next and prev to recreate chain
	head.header.prev.next = head.header.next;
	head.header.next.prev = head.header.prev;

	// Set the Queue header to next
	head.header = head.header.next;
	
	return item;
}

struct q_elem* newItem() {
	struct q_elem *item = (struct q_elem*) malloc(sizeof(struct q_elem));
	return item;
}

void printQueue(struct queue &head) {
	struct q_elem item = head.header;
	struct q_elem last = head.header.prev;

	while (item != NULL && item.payload != last.payload) {
		printf("PAYLOAD: %d\n", item);
		item = item.next;
	}

	printf("\n");

	return;
}

#endif
