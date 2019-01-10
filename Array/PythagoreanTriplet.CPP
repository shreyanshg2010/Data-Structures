Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[i] <= 1000

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

Explanation:
For testcase1: a=3, b=4, and c=5 forms a pythagorean triplet, so we print "Yes"



#include <iostream>
using namespace std;

int main() {
	int t,n,i,j,f=0;
	cin>>t;
	while(t--)
	{f=0;
	    cin>>n;int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    for(i=0;i<n;i++)
	    {if(f==1)
	    break;
	        for(j=i+1;j<n;j++)
	        {if(f==1)
	        break;
	            for(int k=j+1;k<n;k++)
	            {
	                if((a[i]*a[i]+a[j]*a[j])==(a[k]*a[k]))
	                {cout<<"Yes"<<endl;f=1;break;}
	            }
	            
	        }
	    }
	    if(f==0)
	    cout<<"No"<<endl;
	}
	return 0;
}
