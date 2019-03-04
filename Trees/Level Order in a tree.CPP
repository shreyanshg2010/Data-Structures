Level order traversal of a tree is obtained by doing a breadth first search on it.

You are given a tree with N nodes and N-1 edges. Each edge is bidirectional and connects two nodes.

The nodes of the tree are indexed from 1 to N and you can consider 1 to be the root of the tree.

You are given an integer d. Your task is to print the number of nodes that are present at the dth level of the tree.

It is guaranteed that atleast one node will be present at the dth level.

Input

First line contains n the number of nodes 
Next n - 1 lines each contain two integers u and v such that there is an edge between u and v 
Last line contains the integer d

Output

Print one number, the count of nodes at dth level of the tree

Sample Input 0

20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2
Sample Output 0

3



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
int main(){
    vector<int> adj[100003];
    int n,i,x,a1,b,f=0,level[100004],c=0;
    bool a[100002];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a1,&b);
        adj[a1].push_back(b);
        adj[b].push_back(a1);
        a[i]=false;
    }
    scanf("%d",&x);
    queue <int> q;
    level[ 1 ] = 1 ;
    q.push(1);
    a[1]=true;
    if(x==1) printf("0\n");
    else{
        while(!q.empty()){
        int p=q.front();
        q.pop();
        for(i=0;i<adj[p].size();i++){
                if(a[adj[p][i]]==false){
                    level[ adj[ p ][ i ] ] = level[ p ]+1; 
                    if(level[adj[p][i]]==x) c++;
                    if(level[p]==x) break;
                    q.push(adj[p][i]);
                    a[adj[p][i]]=true;
                }
            }
        }
        printf("%d\n",c);
    }
}
