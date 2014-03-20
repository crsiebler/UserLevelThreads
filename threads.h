// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: Holds routines to start threads, yield, and run

#ifndef THREADS_H
#define THREADS_H

void start_thread(void (*function)(void));
void run();
void yield();

#endif
