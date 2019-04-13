input
3
1 2 3
4

output:
4


#include<bits/stdc++.h>
using namespace std;
int count( int S[], int m, int n ) 
{ 
	int table[n+1]; 
	memset(table, 0, sizeof(table));
	table[0] = 1; 
	for(int i=0; i<m; i++) 
		for(int j=S[i]; j<=n; j++) 
			table[j] += table[j-S[i]]; 

	return table[n]; 
} 
int main() 
{ 
    int m,i;
    cin>>m;
    int arr[m];
    for(i=0;i<m;i++)
    cin>>arr[i];
    int n;
    cin>>n;
    cout << count(arr, m, n); 
    return 0; 
} 
  
