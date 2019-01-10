Given an array A of positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1018

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6




#include <iostream>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n,min=0,k=0; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=n-1;i>=0;i--)
	    {
            for(int j=0;j<n;j++)
            {
                if(a[j]<=a[i])
                {
                    k=i-j;
                    if(k>min)
                        min=k;
                    break;
                }
            }
	    }
	    cout<<min<<endl;
	    
	}
	return 0;
}
