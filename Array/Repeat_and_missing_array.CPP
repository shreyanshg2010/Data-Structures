You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4


#include <iostream>
#include <vector> 
#include<climits>
using namespace std;
int repeatedNumber(const vector<int> &A) {
  long long int n=A.size();
    long long int sum=0;
    long long int diff;
    long long int square=0;
    long long int a;
    for(long long int i=0;i<A.size();i++){
        sum+=(long long)A[i];
        square+= (long long)A[i]*(long long)A[i];
        
    }
        
    diff= n*(n+1)/2- sum;
    a= n*(n+1)*(2*n+1)/6 -square;
    long long int b;
    b=a/diff;
    
    vector<int>B;
    while (B.empty()){
    B.push_back((b-diff)/2);
    B.push_back((b+diff)/2);}
    for(int i=0;i<B.size();i++){
    cout<<B[i]<<" ";}
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
  
    cout<<repeatedNumber(A);
    return 0;
}
