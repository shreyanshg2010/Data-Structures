
     

Given a long integer, we need to find if the difference between sum of digits present at the odd positions and sum of digits present at even positions is 0 or not. The indexes start from zero (0 index is for leftmost digit).

Input:
First line consists of T test cases. Only line of every test case consists of a number N.

Output:
Print "Yes" if difference is 0 else print "No".

Constraints:
1<=T<=300
1<=N<=1018

Example:
Input:
2
1212112
123
Output:
Yes
No



#include<iostream> 
#include<string>

using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t--) {
        long long int n, p;
        cin>>n;
        p = n;
        int c = 0;
        while(p > 0){
            p = p / 10;
            ++c;
        }
        
        int v[c];
        p = n;
        for(int i = c-1; i >= 0; i--){
            v[i] = p % 10;
            p = p / 10;
        }
        
        int a = 0, b = 0;
        for(int i = 0; i < c; ++i){
            if(i % 2 == 0)
                a += v[i];
            else
                b += v[i];
        }
        
        if(a == b) cout << "Yes\n";
        else cout << "No\n";
        
    }
	return 0;
}
