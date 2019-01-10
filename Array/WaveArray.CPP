Given a sorted array A of non-repeating integers without duplicates. Sort the array into a wave-like array and return it. In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.

Output:
Print the array into wave-like array.

Constraints:
1 ≤ T ≤ 130
1 ≤ N ≤ 106
0 ≤ A[i] ≤107

Example:
Input:
1
5
5 7 3 2 8
Output:
3 2 7 5 8



#include<iostream>
using namespace std;

#define ll long long int

int main()
 {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll a[n];
	    for(ll i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	    for(int i=0;i<n-1;i+=2)
	    {
	        swap(a[i],a[i+1]);
	    }
	    for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
	}
	return 0;
 }
