// Name: Cory Siebler & Marcus Finney
// Class: CSE430 #12109
// Assignment: Project 2
// Description: initializes the TCB Queue and pointer for thread context 

#ifndef TCB_H
#define TCB_H

#include <sys/ucontext.h>
#include <stdio.h>
#include <string.h>

//----------------------------//
// Data Structure Declaration //
//----------------------------//
typedef struct TCB_t {
     struct TCB_t *next;
     struct TCB_t *prev;
     ucontext_t context;
} TCB_t;

//-----------------//
// init_TCB Method //
//-----------------//
void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size) {
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}

#endif
