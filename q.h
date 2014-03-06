#ifndef Q_H
#define Q_H

//----------------------------//
// Method Forward Declaration //
//----------------------------//
void initQueue(&head);	// creates an empty queue, pointed to by the variable head
void addQueue(&head, item);	// adds a queue item, pointed to by "item", to the queue pointed to by head
void rotateQ(&head);	// Moves the header pointer to the next element in the queue
item delQueue(&head);	// deletes an item from head and returns a pointer to the delete item
item newItem();	// returns a pointer to a new q-element

#endif
