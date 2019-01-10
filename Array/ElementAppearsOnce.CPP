Given an array of integers. All numbers occur twice except one number which occurs once. Find the number in O(n) time & constant extra space.

Example :

Input:  ar[] = {7, 3, 5, 4, 5, 3, 4}
Output: 7 



The best solution is to use XOR. XOR of all array elements gives us the number with single occurrence. The idea is based on following two facts.
a) XOR of a number with itself is 0.
b) XOR of a number with 0 is number itself.



Let us consider the above example.  
Let ^ be xor operator as in C and C++.

res = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4

Since XOR is associative and commutative, above 
expression can be written as:
res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)  
    = 7 ^ 0 ^ 0 ^ 0
    = 7 ^ 0
    = 7 
    
#include <iostream> 
using namespace std; 
  
int findSingle(int ar[], int ar_size) 
    { 
        // Do XOR of all elements and return 
        int res = ar[0]; 
        for (int i = 1; i < ar_size; i++) 
            res = res ^ ar[i]; 
  
        return res; 
    } 
  
// Driver code 
int main() 
    { 
        int ar[] = {2, 3, 5, 4, 5, 3, 4}; 
        int n = sizeof(ar) / sizeof(ar[0]); 
        cout << "Element occurring once is " 
             << findSingle(ar, n); 
        return 0; 
    } 
