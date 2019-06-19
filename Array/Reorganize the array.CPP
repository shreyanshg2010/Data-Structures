Given an array of elements of length N, ranging from 0 to N-1, your task is to write a program that rearranges the elements of the array. All elements may not be present in the array, if element is not present then there will be -1 present in the array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

Examples:

Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
         11, 12, 13, 14, 15, 16, 17, 18, 19]



#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	  int n,i,j,k;
	  cin>>n;
	  int a[n];
	  for(i=0;i<n;i++)
	   cin>>a[i];
	   
	  int h[n]={0};
	   
	    for(i=0;i<n;i++)
	  {
	      if(a[i]!=-1)
	      h[a[i]]++;
	  }
	   for(i=0;i<n;i++)
	   {
	       if(h[i])
	        cout<<i<<" ";
	        else
	        cout<<"-1"<<" ";
	   }
	   cout<<endl;
	}  
 return 0;
}
