//
// Created by Mahmoud on 10/8/2017.
//

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    int data;
    struct stackNode *nextPtr;
};

void push(struct stackNode **topPtr, int info);
int pop(struct stackNode **topPtr);
int isEmpty(struct stackNode *topPtr);
void printStack(struct stackNode *currentPtr);
void instructions(void);

#endif //STACK_MYSTACK_H
