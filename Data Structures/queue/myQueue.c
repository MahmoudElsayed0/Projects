//
// Created by Mhamoud on 10/13/2017.
//

#include "myQueue.h"


void instructions(void)
{
    printf("Enter your choice: \n"
                   "1 to add an item to the queue.\n"
                   "2 to remove an item from the queue.\n"
                   "3 to end.\n");
}/*End of instructions function*/

void enqueue(QueueNodePtr* headPtr,QueueNodePtr* tailPtr, int info)
{
    QueueNodePtr newPtr;

    newPtr = malloc (sizeof(QueueNode));

    if(newPtr != NULL)
    {
        newPtr->data = info;
        newPtr->nextPtr = NULL;
        // Take the pointed struct and open it
        // add the address for the new queue element to the last one
        if(!isEmpty(*headPtr))
            (*tailPtr)->nextPtr = newPtr;
        else
            *headPtr= newPtr;
        /*End of If*/
        *tailPtr = newPtr;
    }/*End if*/
    else
        printf("%d not inserted, No memory available.\n",info);
}/*End of enqueue Function*/

int dequeue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr)
{
    int value;
    QueueNodePtr tempPtr;

    if(!isEmpty(*headPtr))
    {
        tempPtr = *headPtr;
        value = (*headPtr)->data;
        *headPtr = (*headPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        printf("The queue is Empty\n");
        *tailPtr = NULL;
    }


}
int isEmpty(QueueNodePtr headPtr)
{
    return headPtr == NULL;
}/*End of is Empty Function*/

void printQueue( QueueNodePtr currentPtr )
{
    if( currentPtr == NULL)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue is: \n");

        while(currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }/*End of while*/

        printf("NULL\n");
    }
}/*End of print Queue function */