Input : str[] = "GFGFG"
Output : 4
GFGFG, GFGFG, GFGFG, GFGFG

Input : str[] = "ABCFGFPG"
Output : 1

#include <bits/stdc++.h> 
using namespace std; 
#define MAX 100 
  
// Print the count of "GFG" subsequence in the string 
void countSubsequence(char s[], int n) 
{ 
    int cntG = 0, cntF = 0, result = 0, C=0; 
  
    // Traversing the given string 
    for (int i = 0; i < n; i++) { 
        switch (s[i]) { 
  
        // If the character is 'G', increment 
        // the count of 'G', increase the result 
        // and update the array. 
        case 'G': 
            cntG++; 
            result+=C; 
            break; 
  
        // If the character is 'F', increment 
        // the count of 'F' and update the array. 
        case 'F': 
            cntF++; 
            C+=cntG; 
            break; 
  
        // Ignore other character. 
        default: 
            continue; 
        } 
    } 
  
    cout << result << endl; 
} 
  
// Driven Program 
int main() 
{ 
    char s[] = "GFGFG"; 
    int n = strlen(s); 
    countSubsequence(s, n); 
    return 0; 
} 
