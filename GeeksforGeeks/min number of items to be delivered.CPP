Input : 
N = 5
A[] = { 1, 3, 5, 7, 9 }
K = 10
Output : 3
By delivering 3 items at a time, 
Number of tours required for bucket 1 = 1
Number of tours required for bucket 2 = 1
Number of tours required for bucket 3 = 2
Number of tours required for bucket 4 = 3
Number of tours required for bucket 5 = 3
Total number of tours = 10


//C++ program to find the minimum numbers of tours required 
#include <bits/stdc++.h> 

using namespace std; 
int getMin(int N,int A[],int k) 
{ 
	//Iterating through each possible 
// value of minimum Items 
int maximum=0,tours=0; 
	
for(int i=0;i<N;i++) 
	maximum=max(maximum,A[i]); 
		
for(int i=1;i<maximum+1;i++) 
{ 
	tours=0; 
	for(int j=0;j<N;j++) 
	{ 
		if(A[j]%i==0)//perfecctly Divisible 
		{ 
			tours+=A[j]/i; 
		}else{ 
				// Not Perfectly Divisible means required 
				// tours are Floor Division + 1 
				tours += floor(A[j]/i) + 1; 
		} 
	} 
	if(tours<=k) 
	{ 
			// Return First Feasible Value found, 
			// since it is also the minimum 
			return i; 
	} 
} 
	
return -1; 
} 
//Driver code 
int main() 
{ 
int a[]={1,3,5,7,9}; 
	
int n=sizeof(a)/sizeof(a[0]); 
	
int k=10; 
	
if(getMin(n,a,k)==-1) 
cout<<"Not Possible"; 
else
cout<<getMin(n,a,k); 
	
} 
