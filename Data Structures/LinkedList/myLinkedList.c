//
// Created by Mhamoud on 10/18/2017.
//
#include "myLinkedList.h"


void insert(LinkedListPtr* sPtr,char value)
{
    LinkedListPtr newPtr;
    LinkedListPtr previousPtr;
    LinkedListPtr currentPtr;

    newPtr = malloc( sizeof(LinkedList) );

    if(newPtr == NULL)
        printf("%c not inserted. No memory available.\n", value);
    else {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        //newPtr->nextPtr = (*sPtr)->nextPtr;
        //(*sPtr)->nextPtr = newPtr;

        previousPtr = NULL;
        currentPtr = *sPtr;
        //while( currentPtr != NULL )
        while( currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }/*End of while*/

        if(previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }/*End if*/
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }/*End else*/

    }/*End else*/
}/*End of insert*/


char delete(LinkedListPtr* sPtr, char value)
{
    LinkedListPtr previousPtr;
    LinkedListPtr currentPtr;
    LinkedListPtr tempPtr;
    if( value == (*sPtr)->data)
    {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;

    }/*End if*/
    else
    {
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while( currentPtr != NULL && value != currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }/*End while*/
        if(currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }/*End if*/
    }/*End else*/
    return '\0';
}/*End of delete*/

int isEmpty(LinkedListPtr sPtr)
{
    return sPtr == NULL;
}/*End of isEmpty*/

void printList(LinkedListPtr sPtr)
{
    if( sPtr == NULL)
        printf("\nLis is Empty.\n");
    else
    {
        printf("\nThe list is: \n");

        while(sPtr != NULL)
        {
            printf("%c --> ", sPtr->data);
            sPtr= sPtr->nextPtr;
        }/*End while*/
        printf("NULL");
    }/*End else*/
}/*End printList*/

void instractions(void)
{
    printf("Enter your choice: \n"
                   "1 to insert an element to the list.\n"
                   "2 to delete an element from the list\n"
                   "3 to exit\n");
}/*End of instractions*/
