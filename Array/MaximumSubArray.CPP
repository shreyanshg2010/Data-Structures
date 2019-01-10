Maximum Sub Array Submissions: 8414   Accuracy: 24.22%   Difficulty: Medium   Marks: 4
        
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the Sub-array with maximum sum.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
-100 ≤ A[i] ≤ 100

Example:
Input
2
3
1 2 3
2
-1  2
Output
1 2 3
2




using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int count=0,c1=0,sum=0,sum1=-1,index=0,ind=0;
	int a[n],i;
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]>=0)
	    {
	        sum+=a[i];
	        count++;
	        if(sum>sum1||(sum==sum1 && count>c1))
	        {
	            sum1=sum;
	            c1=count;
	            ind=index;
	        }
	    }
	    else
	    {
	        sum=0;
	        index=i+1;
	        count=0;
	        
	    }
	    
	}
	
	for(i=ind;i<ind+c1;i++)
	{
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	}
	return 0;
}
