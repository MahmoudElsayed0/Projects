//
// Created by Mhamoud on 10/13/2017.
//

#ifndef QUEUE_MYQUEUE_H
#define QUEUE_MYQUEUE_H
#include <stdio.h>
#include <stdlib.h>


typedef struct queueNode {
    int data;
    struct queueNode *nextPtr;
} QueueNode;/*End of Queue struct*/

typedef QueueNode *QueueNodePtr;
void enqueue(QueueNodePtr* headPtr,QueueNodePtr* tailPtr, int info);
int dequeue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr);
int isEmpty(QueueNodePtr headPtr);
void printQueue( QueueNodePtr currentPtr );
void instructions(void);
#endif //QUEUE_MYQUEUE_H
