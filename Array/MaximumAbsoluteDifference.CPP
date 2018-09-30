You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.


#include <iostream>
#include <vector> 
#include<climits>
using namespace std;
int maxArr(vector<int> &A) {
    int max1 , max2 , min1 , min2;
    max1 = max2 = INT_MIN;
    min1 = min2 = INT_MAX;
    int N = A.size();
    for(int i=0;i<N;i++){
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    int ans = 0;
    ans = max(ans,max1-min1);
    ans = max(ans,max2-min2);
    return ans;
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
   for (int i:A) 
        cout << i<< " "; 
  
    cout<<maxArr(A);
    return 0;
}

