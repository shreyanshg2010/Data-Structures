#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define scan(x) scanf(" %d", &x)
struct TreeNode {
    int x;
    struct TreeNode* L;
    struct TreeNode* R;
};
typedef struct TreeNode TreeNode;
TreeNode* newNode(int _x) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->x = _x;
    node->L = node->R = NULL;
  return node;
}
TreeNode* insert(TreeNode* node, int val) {
    if (node == NULL) return newNode(val);
    if (val <= node->x) node->L = insert(node->L, val);
    else node->R = insert(node->R, val);
return node;
}

void printPreorder(TreeNode* root)
{if(root == NULL)
    return;
 printf("%d ",root->x);
 printPreorder(root->L);
 printPreorder(root->R);}

void printPostorder(TreeNode* root)
{if(root == NULL)
    return;
 printPostorder(root->L);
 printPostorder(root->R);
printf("%d ",root->x);}

void printInorder(TreeNode* root)
{if(root == NULL)
    return;
 printInorder(root->L);
 printf("%d ",root->x);
 printInorder(root->R);}

// Driver program to test above functions 
int main() {
    int val, N; scan(N);
    TreeNode* Root = NULL;
    for (int i = 1; i <= N; i++) {
        scan(val);
        Root = insert(Root, val);
    }

    printPreorder(Root);
    printf("\n");
    printInorder(Root);
    printf("\n");
    printPostorder(Root);

    return 0; 
} 
