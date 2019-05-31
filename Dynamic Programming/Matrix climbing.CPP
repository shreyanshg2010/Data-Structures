1 2 3 4
5 6 7 8 
9 10 11 12
13 14 15 16
start->1
end->16
The man can move only in two directions that is down or right.
We have to calculate the maximum sum from the starting path to the end of the node .

#include <bits/stdc++.h>
using namespace std;
const int N=1003;
int n,m,a[N][N],vis[N][N],dp[N][N];
int go(int i,int j){
    if(i==n-1 && j==m-1){
        return a[i][j];
    }
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=1;
    int &ans=dp[i][j];
    if(i<n-1 && j<m-1){
        ans=a[i][j]+max(go(i+1,j),go(i,j+1));
    }
    else if(i==n-1){
        ans=a[i][j]+go(i,j+1);
    }
    else
        ans=a[i][j]+go(i+1,j);
    return ans;
}
int main()
{
	int i,j;
	cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<go(0,0);
	
	
	
	return 0;
} 
