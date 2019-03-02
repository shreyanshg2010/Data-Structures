Your task is to write a program to print the zigzag level-order traversal of a binary tree. 
Here are a few examples :

  1
 / \
2   3
Traversal : 1 3 2
    1
   / \
  2   3
 / \   \
4   5   6
Traversal : 1 3 2 4 5 6
       1
      / \
     2   3
    / \   \
   4   5   6
  /   /   / \
 7    8  9   10
 Traversal : 1 3 2 4 5 6 10 9 8 7
Input
First line contains the number of nodes N. 
Next N-1 lines contains information about one edge each. 
Each line consists of three values : U V C which denotes that V is a child of U 
If C is 'L' then V is a left child and if C is 'R' then V is a right child

Output
Print the zigzag level order traversal as explained

Sample Input 0

3
1 2 L
1 3 R
Sample Output 0

1 3 2





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100000][2];
int stack1[100000],stack2[10000];
int main() {
     int parent,child;
    char ch;
    int n;
    cin>>n;
    for(int i=0;i<100000;i++)
        for(int j=0;j<2;j++)
            a[i][j]=-1;
    for(int i=1;i<n;i++)
    {
        cin>>parent>>child>>ch;
        if(ch=='L')
        {
            a[parent][0]=child;
        }
        else
            a[parent][1]=child;
    }
    int head1=-1,head2=-1;
        stack1[++head1]=1;
    while(head1!=-1)
    {
        while(head1!=-1)
        {
            if(a[stack1[head1]][0]!=-1)
                stack2[++head2]=a[stack1[head1]][0];
            if(a[stack1[head1]][1]!=-1)
                stack2[++head2]=a[stack1[head1]][1];
            cout<<stack1[head1--]<<" ";
        }
        while(head2!=-1)
        {
             if(a[stack2[head2]][1]!=-1)
                stack1[++head1]=a[stack2[head2]][1];
            if(a[stack2[head2]][0]!=-1)
                stack1[++head1]=a[stack2[head2]][0];
            cout<<stack2[head2--]<<" ";
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
