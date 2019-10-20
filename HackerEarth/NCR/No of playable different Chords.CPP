Suppose that I have a very special Ukulele that contains N frets. I can use atmost 4 fingers to play a chord.
I am required to determine the total number of different chords that I can play.

Note: Two chords are different if one of the frets that are pressed in one of the chords is not pressed in another chord.

That would give an answer of (NC1)+(NC2)+(NC3)+(NC4) which in the case of N=5 would give 5+10+10+5=30
#include<bits/stdc++.h>
using namespace std;

long long int Solve (long long int n) {
   // Write your code here
   long long int sum=0;
   long long int dp[n+1][n+1];
  
   if(n==1) return 1;
   if(n==2) return 3;
   if(n==3) return 7;
    for(long long int i=0;i<=n;i++){
        for(long long int j=0;j<=min(i,n);j++){
            if(j==0 || j==i){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=(dp[i-1][j-1]%1000000007+dp[i-1][j]%1000000007)%1000000007;
            }
        }
    }
       
    for(long long int i=1;i<=4;i++){
        sum+=dp[n][i]%1000000007;
    }
   return sum%1000000007;
}

    
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int N;
    cin >> N;

    long long int out_;
    out_ = Solve(N);
    cout << out_;
}
