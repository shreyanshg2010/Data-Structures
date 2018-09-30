Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index


#include <iostream>
#include <vector> 
#include<climits>
using namespace std;
int maxset(vector<int> &A) {
    long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, sumTillNow = INT_MIN, maxTillNow=INT_MIN;
   int i=0;
   
   while(i<A.size()){
       if(A[i]>=0){
            start = i;
            sumTillNow =0;
            length =0;
            
            while(A[i]>=0 && i<A.size()){
                sumTillNow +=A[i];
                i++;   
            }
            end = i-1;
            
           if( ( sumTillNow>maxTillNow ) || ( sumTillNow==maxTillNow && end - start +1 < ansLength ) ){
               ansStart = start;
               ansEnd = end;
               ansLength = start + end -1 ;
               maxTillNow = sumTillNow;
            }
       }
       i++;
       
    }
       vector <int> ans;
       for(int i=ansStart; i<=ansEnd;i++){
           ans.push_back(A[i]);
       }
       
       for(i:ans){
           cout<<i<<" "; 
       }
}
int main()
{
    vector<int> A;
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        A.push_back(i);
        cin>>A[i];
    }
   //for (int i:A) 
       // cout << i<< " "; 
  
    cout<<maxset(A);
    return 0;
}
