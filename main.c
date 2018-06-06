// // Creating and traversing a binary search tree
#include <stdio.h>
#include <stdlib.h>  //#include <time.h>
// self-referential structure
struct treeNode {
    struct treeNode *leftPtr; // pointer to left subtree
    int data; // node value
    struct treeNode *rightPtr; // pointer to right subtree
};
typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*
// prototypes
void insertNode(TreeNodePtr *treePtr, int value);
int findSmallestBST(TreeNodePtr treePtr);
int findLargestBST(TreeNodePtr treePtr);
// function main begins program execution
int main(void)
{
    TreeNodePtr rootPtr = NULL; // tree initially empty  //   srand(time(NULL));
    puts("The numbers being placed in the tree are:");
    // insert random values between 0 and 14 in the tree
    int item;
    scanf("%d   ", &item);
    while (item != 0)
    {                                       //     int item = rand() % 15;
        insertNode(&rootPtr, item);
        scanf("%d   ", &item);               //      printf("%3d", item);
    }
    // Smallest and Largest
    printf("\n\nThe Smallest of BST is:-- %d", findSmallestBST(rootPtr));
    puts("\n\nThe Largest of BST is:");
    findLargestBST(rootPtr);
}
// insert node into tree
void insertNode(TreeNodePtr *treePtr, int value)
{
    // if tree is empty
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));
        // if memory was allocated, then assign data
        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else { // tree is not empty
        // data to insert is less than data in current node
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }
            // data to insert is greater than data in current node
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
        else { // duplicate data value ignored
            printf("%s", "dup");     }
    }
}
// Find Smallest
int findSmallestBST(TreeNodePtr treePtr)
{
    if(treePtr == NULL)
    {
        return -9999;
    }
    while(treePtr->leftPtr != NULL)
    {
        treePtr = treePtr->leftPtr;
        return treePtr->data;
    }
} // findSmallestBST

int findLargestBST(TreeNodePtr treePtr)
{
    if(treePtr == NULL)
    {
        return -1;
    }
    if(treePtr->rightPtr == NULL)
    {
        return treePtr->data;
    }
    else findLargestBST(treePtr->rightPtr);
}