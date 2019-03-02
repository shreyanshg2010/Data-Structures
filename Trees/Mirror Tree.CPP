When a tree is reflected across an imaginary straight vertical line right or left of the entire tree, the resultant tree hence obtained is the mirror tree of the original tree.

Your task is to write a program to check if two given trees are mirrors of each other.

Input
First line consists of the number of nodes N. 
Next N-1 lines each describes the first tree. Each line has two integers U and V and a letter 'R' or 'L', denoting that V is the left or the right child of U. 
Next N-1 lines each describes the second tree. Each line has two integers U and V and a letter 'R' or 'L', denoting that V is the left or the right child of U.

Output
Print "yes" if the two trees are mirrors of each other and "no" otherwise

Sample Input 0

3
1 2 R
1 3 L
1 2 L
1 3 R
Sample Output 0

yes
Explanation 0

The first tree is

  1 

 / \ 

3   2
The second tree is

  1 

 / \ 

2   3
Clearly, both the trees are mirrors of each other.





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int x;
    node *l, *r;
};

node* newNode(int x){
    node *temp = new node;
    temp->x = x;
    temp->l = temp->r = NULL;
    return temp;
}

node* locate(node* root, int x){
    if(root == NULL || root->x == x){
        return root;
    }
    node* location = locate(root->l, x);
    if(location == NULL){
        location = locate(root->r,x);
    }
    return location;
}

node* insert(node *root, int x, int y, char c){
    node* temp = locate(root, x);
    if(temp == NULL){
        temp = newNode(x);
        root = temp;
    }
    if(c == 'L'){
        temp->l = newNode(y);
    }else{
        temp->r = newNode(y);
    }
    return root;
}

string tr1,tr2;

void inorder1(node *root){
    if(root == NULL){
        return;
    }
    inorder1(root->l);
    tr1 += root->x;
    inorder1(root->r);
}

void inorder2(node *root){
    if(root == NULL){
        return;
    }
    inorder2(root->r);
    tr2 += root->x;
    inorder2(root->l);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,x,y;
    tr1 = tr2 = "";
    char c;
    cin>>n;
    node *r1, *r2;
    r1 = r2 = NULL;
    for(int i = 0; i < n-1; ++i){
        cin>>x>>y>>c;
        r1 = insert(r1,x,y,c);
    }
    for(int i = 0; i < n-1; ++i){
        cin>>x>>y>>c;
        r2 = insert(r2,x,y,c);
    }
    inorder1(r1);
    inorder2(r2);
    if(tr1 == tr2){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}
