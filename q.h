// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 1
// Description: Stores routines to initialize, add, rotate, and delete queues.
//		Also has function to create a new element in the queue and to free deleted elements.

#ifndef Q_H
#define Q_H

//----------------------------//
// Data Structure Declaration //
//----------------------------//
typedef struct q_elem {
	q_elem *prev;
	q_elem *next;
	int payload;
};

typedef struct queue {
	q_elem *head;
};

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void initQueue(queue);	// creates an empty queue, pointed to by the variable head
void addQueue(queue, q_elem);	// adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(queue);	// Moves the header pointer to the next element in the queue
q_elem delQueue(queue);	// deletes an item from head and returns a pointer to the deleted item
q_elem newItem();	// returns a pointer to a new q-element

//-------------------//
// Routine Functions //
//-------------------//
void initQueue(queue &head) {
	// Allocate space for new Queue
	head = malloc(sizeof(struct queue));
	
	return;
}

void addQueue(queue &head, q_elem item) {
	// Doubly Linked List so grab last node
	q_elem last = head.head.prev;
	last.next = item; // Make link from last element
	head.prev = item; // Make link to end from head
	
	return;
}

void rotateQ(queue &head) {
	// Move Head Pointer to Next Element
	head = head.head.next;
	
	return;
}

queue delQueue(&head) {
	q_elem item;
	return item;
}

queue newItem() {
	q_elem item = malloc(sizeof(struct q_elem));
	return item;
}

#endif
