//
// Created by Mhamoud on 10/18/2017.
//

#ifndef MYTREE_MYTREE_H
#define MYTREE_MYTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode{
    struct treeNode* leftPtr;
    int data;
    struct treeNode* rightPtr;

} TreeNode;

typedef TreeNode* TreeNodePtr;

void insertNode( TreeNodePtr* treePtr, int value);
void inOrder( TreeNodePtr treePtr);
void preOrder( TreeNodePtr treePtr);
void postOrder( TreeNodePtr treePtr);

#endif //MYTREE_MYTREE_H
