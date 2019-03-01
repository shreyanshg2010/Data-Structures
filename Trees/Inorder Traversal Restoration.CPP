A complete binary tree is a binary tree where every node except the leaf node has two child nodes and the last level of the tree for an edge-height h has 2^h leaf-nodes.

Your task is simple, given the postorder traversal for a complete binary tree, print it's inorder traversal.

The elements in the binary tree are of type character i.e. each node stores one character value.

Input Format

Only one string input denoting the postorder traversal.

Constraints

1 <= input.length <= 1000

Output Format

output one string that denotes the inorder traversal of the binary tree

Sample Input 0

BCA
Sample Output 0

BAC





#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char po[1000];
void inorder(int s,int n){
    if(s==n){
        printf("%c",po[n]);
        return;
    }
    int l1;
    l1=((s+n)/2);
    inorder(s,l1-1);
    printf("%c",po[n]);
    inorder(l1,n-1);
}

int main() {
    scanf("%s",po);
    int n=strlen(po);
    inorder(0,n-1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
