//
// Created by Mahmoud on 10/9/2017.
//
#include "myStack.h"

void instructions(void)
{
    printf("Enter choice:\n"
                   "1 to push a value on the stack\n"
                   "2 to pop a value off the stack\n"
                   "3 to end the program \n");
}/*End of function instructions*/

void push(struct stackNode **topPtr, int info)
{
    struct stackNode* newPtr;
    newPtr = malloc( sizeof( struct stackNode ) );
    if( newPtr != NULL )
    {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }/*End of if*/
    else
        printf(" No memory available\n");
}/*End of push*/

int pop( struct stackNode **topPtr )
{
    struct stackNode *tempPtr;
    int value;
    if(topPtr != NULL)
    {
        tempPtr = *topPtr;
        value    = (*topPtr) ->data;
        *topPtr = (*topPtr) ->nextPtr;
        free(tempPtr);
        return value;
    }
    else
        printf(" Stack is Empty \n");
    return 0;
}/*End of pop*/

void printStack( struct stackNode *currentPtr)
{
    if( currentPtr == NULL)
        printf(" Stack is Empty \n");
    else
    {
        printf(" Stack is: \n");

        while( currentPtr != NULL )
        {
            printf("%d -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}/*End of printStack*/

int isEmpty( struct stackNode *topPtr)
{
    return topPtr ==NULL;
}/*End of isEmpty*/