#include <bits/stdc++.h> 
using namespace std; 
  
int countOccurrences(string s, int K) 
{ 
    int n = s.length(); 
    int C, c1 = 0, c2 = 0; 
    for (int i = 0; i < n; i++) { 
        if (s[i] == 'a') 
            c1++; // Count of 'a's 
        if (s[i] == 'b') { 
            c2++; // Count of 'b's 
            C += c1; // occurrence of "ab"s in string S 
        } 
    } 
  
    // Add following two : 
    // 1) K * (Occurrences of "ab" in single string) 
    // 2) a is from one string and b is from other. 
    return C * K + (K * (K - 1) / 2) * c1 * c2; 
} 
  
// Driver code 
int main() 
{ 
    string S = "abcb"; 
    int k = 2; 
    cout << countOccurrences(S, k) << endl; 
    return 0; 
} 
