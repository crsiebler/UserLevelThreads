// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: 

#include "threads.h"

struct queue *readyQ;

void f1()
{
	while(1)
	{}
}
void f2()
{
	while(1)
	{}
}

int main() {
	struct queue *readyQ = (struct queue*) malloc(sizeof(struct queue));
	initQueue(readyQ);

	startThread(f1());
	startThread(f2());
	run();

	return 0;
}
