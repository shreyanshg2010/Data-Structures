input
10 120
1 2 3 4 5 6 7 8 9 10

output:
23785645


#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int A[N],n;
int vis[N][N],dp[N][N];

int ways(int pos,int S){
    if(pos==n)
        return S==0;
    int &ans=dp[pos][S];
    if(vis[pos][S]) return ans;
    vis[pos][S]=1,ans=0;
    int times=0;
    while(times*A[pos]<=S) ans+=ways(pos+1,S-times*A[pos]),times++;
    return ans;
}
//Faster than ways function as it causes only two transitions
int fasterWays(int pos, int S) {
	if(pos == n) return S == 0;
 	 if(S < 0) return 0;
	int &ans = dp[pos][S];
 	 if(vis[pos][S]) return ans; vis[pos][S] = 1, ans = 0;
	ans = fasterways(pos, S-A[pos]) + fasterways(pos+1, S);
	return ans;
}

int main(){
    int i,S;
    cin>>n>>S;
    for(i=0;i<n;i++){
        cin>>A[i];}
    cout<<ways(0,S);
    return 0;
} 
  
