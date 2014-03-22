// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 1
// Description: Stores routines to initialize, add, rotate, and delete queues.
//		Also has function to create a new element in the queue and to free deleted elements.

#ifndef Q_H
#define Q_H

//---------------//
// Include Files //
//---------------//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//----------------------------//
// Data Structure Declaration //
//----------------------------//
typedef struct q_elem {
	struct q_elem *prev; // Pointer to Previous Element
	struct q_elem *next; // Pointer to Next Element
	int payload; // Integer to store data for Element
} q_elem;

typedef struct queue {
	struct q_elem *header; // Pointer to 1st Element in Queue
} queue;

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void initQueue(struct queue*); // creates an empty queue, pointed to by the variable head
void addQueue(struct queue*, struct q_elem*); // adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(struct queue*); // Moves the header pointer to the next element in the queue
struct q_elem* delQueue(struct queue*); // deletes an item from head and returns a pointer to the deleted item
struct q_elem* newItem(); // returns a pointer to a new q-element
void printQueue(struct queue*); // prints the queue's elements

//-------------------//
// Routine Functions //
//-------------------//

//------------------//
// initQueue Method //
//------------------//
void initQueue(struct queue *head) {
	// Allocate space for new Queue
	head->header = NULL;
	
	return;
}

//-----------------//
// addQueue Method //
//-----------------//
void addQueue(struct queue *head, struct q_elem *item) {
	// Check for 0 elements in Queue
	if (head->header != NULL) {
		// Check for single or multiple elements
		if (head->header->next != NULL) {
			// Queue is not empty, break chain and insert new item to end
			item->prev = head->header->prev; // Add new link at end of chain
			item->next = head->header; // Attach new link to beginning of chain
			head->header->prev->next = item; // Make link from last element
			head->header->prev = item; // Make link to end from head
		} else {
			// Queue has 1 Element so create new chain
			head->header->next = item; // Add new link to new item
			head->header->prev = item; // Create chain linking to last element
			item->next = head->header; // Create chain linking to first element
			item->prev = head->header; // Add new link to old item
		}
	} else {
		// Queue is empty
		head->header = item; // Make header point to new item
		item->prev = NULL; // Only 1 element so set to NULL
		item->next = NULL; // Only 1 element so set to NULL
	}
	
	return;
}

//-----------------//
// rotQueue Method //
//-----------------//
void rotQueue(struct queue *head) {
	// Move head pointer to next Element
	// Put first element at end of Queue
	addQueue(head, delQueue(head));
	
	return;
}

//-----------------//
// delQueue Method //
//-----------------//
struct q_elem* delQueue(struct queue *head) {
	// Grab the first element in the Queue
	struct q_elem *item = head->header;

	// Check for empty Queue
	if (head->header != NULL) {
		// Check for single or multiple elements in Queue
		if (head->header->next != NULL) {
			// Grab the last element and next element
			// Assign next and prev to recreate chain
			head->header->prev->next = head->header->next;
			head->header->next->prev = head->header->prev;
	
			// Set the Queue header to next
			head->header = head->header->next;
		} else {
			// Remove single element from Queue
			head->header = NULL;
		}
	}
	
	return item;
}

//----------------//
// newItem Method //
//----------------//
struct q_elem* newItem() {
	// Allocate memory for new Queue element
	struct q_elem *item = (struct q_elem*) malloc(sizeof(struct q_elem));
	
	// Verify memory is allocated
	if (!item) {
		item->prev = NULL; // Initialize Previous Element
		item->next = NULL; // Initialize Next Element
		item->payload = 0; // Initialize Payload
	}

	return item;
}

//-------------------//
// printQueue Method //
//-------------------//
void printQueue(struct queue *head) {
	struct q_elem *item = head->header; // Grab first item in chain to iterate
	struct q_elem *last = head->header->prev; // Grab last item in chain

	// Loop through elements until last element found
	while (item != NULL && (item->payload != last->payload)) {
		printf("PAYLOAD: %d\n", item->payload); // Print the element's payload
		item = item->next; // Iterate to next element in Queue
		sleep(1);
	}

	// Check to make sure item is not NULL (i.e. improper Queue implementation)
	if (item != NULL) {
		// Print the last element in the Queue
		printf("PAYLOAD: %d\n", item->payload);
	}

	printf("\n");

	return;
}

#endif
