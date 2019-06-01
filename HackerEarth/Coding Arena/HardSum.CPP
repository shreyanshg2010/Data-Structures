Program for sum of all bitwise or of all ordered pairs.
Input:
2
Output:
9
Explanation:
1|1+1|2+2|1+2|2=9

#include <bits/stdc++.h> 
using namespace std; 
const int mod = 1000000007;
int pairAndSum(int a[], int n) {
    int i, sum = 0, sum1 = 0, j; 
	for (i=0;i<n;i++) 
	{ 
		sum1=0; 
		for (j = i; j < n; j++) 
		{ 
			sum1=(sum1|a[j])%mod; 
			sum=sum+sum1; 
		} 
	} 
	return sum; 
}
int main() 
{ 
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    cout << pairAndSum(arr, n)+sum<< endl; 
    return 0; 
} 
