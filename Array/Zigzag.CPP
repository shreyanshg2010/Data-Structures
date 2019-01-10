Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains a single integer N denoting the size of array.
The second line contains N space-separated integers denoting the elements of the array.

Output:
For each testcase, print the array in Zig-Zag fashion.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= Ai <= 10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3


#include<iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	       cin >> a[i]; 
	    }
	    bool flag=true;
	    for(int i=0;i<n-1;i++)
	    {
	        if(flag)
	        {
	            if(a[i]>a[i+1])
	            {
	                swap(a[i],a[i+1]);
	            }
	        }
	        else
	        {
	            if(a[i]<a[i+1])
	            {
	                swap(a[i],a[i+1]);
	            }
	        }
	        flag = !flag;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout << a[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
