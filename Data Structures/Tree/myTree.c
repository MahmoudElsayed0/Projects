//
// Created by Mhamoud on 10/18/2017.
//
#include "myTree.h"


void insertNode( TreeNodePtr* treePtr, int value)
{
    if( *treePtr == NULL ) {
        *treePtr = malloc(sizeof(TreeNode));
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } /*End if */
        else
            printf("%d not inserted. No memory available.\n", value);
    }/*End if*/
    else
    {
        if( value < (*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr),value);
        else if(value > (*treePtr)->data)
            insertNode(&((*treePtr)->rightPtr),value);
        else
            printf("dup");
    }/*End else*/
}/*End of insertNode*/

void inOrder( TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }/*End if*/
}/*End of inOder*/


void postOrder( TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }/*End if*/
}/*End of postOder*/


void preOrder( TreeNodePtr treePtr)
{
    if(treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }/*End if*/
}/*End of preOder*/
