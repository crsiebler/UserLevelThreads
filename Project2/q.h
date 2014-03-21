// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 1
// Description: Stores routines to initialize, add, rotate, and delete queues.
//		Also has function to create a new element in the queue and to free deleted elements.

#ifndef Q_H
#define Q_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcb.h"

//----------------------------//
// Data Structure Declaration //
//----------------------------//

typedef struct queue {
	struct TCB_t *header; // Pointer to 1st Element in Queue
} queue;

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void initQueue(struct queue*);	// creates an empty queue, pointed to by the variable head
void addQueue(struct queue*, struct TCB_t*);	// adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(struct queue*);	// Moves the header pointer to the next element in the queue
struct TCB_t* delQueue(struct queue*);	// deletes an item from head and returns a pointer to the deleted item
struct TCB_t* newItem();	// returns a pointer to a new q-element

//-------------------//
// Routine Functions //
//-------------------//
void initQueue(struct queue *head) {
	// Allocate space for new Queue
	head->header = NULL;
	
	return;
}

void addQueue(struct queue *head, struct TCB_t *item) {
	if (head->header != NULL) {
		// Queue is not empty, break chain and insert new item to end
		item->prev = head->header->prev; // Add new link at end of chain
		item->next = head->header; // Attach new link to beginning of chain
		head->header->prev->next = item; // Make link from last element
		head->header->prev = item; // Make link to end from head
	} else {
		// Queue is empty, make header point to new item
		head->header = item;
		item->prev = item; // Make pointer to itself
		item->next = item; // Make pointer to itself
	}
	
	return;
}

void rotQueue(struct queue *head) {
	// Move head pointer to next Element
	// Put first element at end of Queue
	addQueue(head, delQueue(head));
	
	return;
}

struct TCB_t* delQueue(struct queue *head) {
	// Grab the first element in the Queue
	struct TCB_t *item = head->header;

	// Grab the last element and next element
	// Assign next and prev to recreate chain
	head->header->prev->next = head->header->next;
	head->header->next->prev = head->header->prev;

	// Set the Queue header to next
	head->header = head->header->next;
	
	return item;
}

struct TCB_t* newItem() {
	// Allocate memory for new Queue element
	struct TCB_t *item = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	
	// Verify memory is allocated
	if (!item) {
		item->prev = NULL; // Initialize Previous Element
		item->next = NULL; // Initialize Next Element
	}

	return item;
}

#endif
