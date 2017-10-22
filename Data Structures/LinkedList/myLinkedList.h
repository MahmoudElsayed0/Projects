//
// Created by Mhamoud on 10/18/2017.
//

#ifndef MYLINKEDLIST_MYLINKEDLIST_H
#define MYLINKEDLIST_MYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList{
    char data;
    struct linkedList* nextPtr;
} LinkedList;

typedef LinkedList* LinkedListPtr;

void insert(LinkedListPtr* sPtr, char value);
char delete(LinkedListPtr* sPtr, char value);
int isEmpty(LinkedListPtr sPtr);
void printList(LinkedListPtr sPtr);
void instractions(void);

#endif //MYLINKEDLIST_MYLINKEDLIST_H
