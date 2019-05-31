You are given a tetrahedron. Let's mark its vertices with letters A, B, C and D correspondingly.


An ant is standing in the vertex D of the tetrahedron. The ant is quite active and he wouldn't stay idle. 
At each moment of time he makes a step from one vertex to another one along some edge of the tetrahedron. 
The ant just can't stand on one place.

You do not have to do much to solve the problem: your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. 
In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself.
As the number can be quite large, you should print it modulo 1000000007 (109 + 7).

Input
The first line contains the only integer n (1 ≤ n ≤ 107) — the required length of the cyclic path.

Output
Print the only integer — the required number of ways modulo 1000000007 (109 + 7).



#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 1e7+2, M = N;

int dp[2][N];
int main()
{
	int i,n,k,j;
	cin >> n;
	dp[1][0] = 1;
	for(int steps = 1; steps < N; steps++){
		dp[1][steps] = (3LL*dp[0][steps-1])%mod;
		dp[0][steps] = (2LL*dp[0][steps-1] + dp[1][steps-1])%mod;
	}
	cout << dp[1][n] << endl;
	
	
	return 0;
} 
