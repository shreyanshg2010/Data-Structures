You are given a binary tree in the form of an array.

Binary tree is represented as an array in the following format :

the value of a node is stored in a[node].
the value for the left child of the node is stored in a[node + node]
the value for the right child of the node is stored in a[node + node + 1]
for any node, if a[node] is 0 it means the node is null
Given the array representation of a binary tree, print its Inorder Traversal

Input Format

First line contains the size of the array N.
Next line contains N integers denoting the array a.

Constraints

1 <= N <= 10^6
a[node] = 0 for node == null otherwise 1 <= a[node] <= 1000

Output Format

Print N integers, the inorder traversal path for the given binary tree.

Sample Input 0

15
1 2 3 4 0 5 6 0 0 0 0 0 0 7 8
Sample Output 0

4 2 1 5 3 7 6 8




#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[1000000];
void preorder(long n,long i){
    if(a[i-1]!=0 && i<=n){
        preorder(n,2*i);
        printf("%d ",a[i-1]);
        preorder(n,(2*i+1));
    }
}
int main() {
    long n;
    scanf("%ld",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    preorder(n,1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

