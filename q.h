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
void initQueue(&head);	// creates an empty queue, pointed to by the variable head
void addQueue(&head, queue);	// adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(&head);	// Moves the header pointer to the next element in the queue
queue delQueue(&head);	// deletes an item from head and returns a pointer to the delete item
queue newItem();	// returns a pointer to a new q-element

//-------------------//
// Routine Functions //
//-------------------//
void initQueue(q_elem &head) {
	struct queue *que;

	que = malloc(sizeof(struct queue));
	
	if (!que) {
		return NULL;
	}
	
	return;
}

void addQueue(&head, queue item) {
	return;
}

void rotateQ(&head) {
	return;
}

queue delQueue(&head) {
	queue item;
	return item;
}

queue newItem() {
	queue item;
	return item;
}

#endif
