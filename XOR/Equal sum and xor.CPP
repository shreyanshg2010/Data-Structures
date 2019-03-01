Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i
Examples :

Input  : n = 7
Output : 1
Explanation:
7^i = 7+i holds only for only for i = 0
7+0 = 7^0 = 7


Input n = 12
Output: 4
12^i = 12+i hold only for i = 0, 1, 2, 3
for i=0, 12+0 = 12^0 = 12
for i=1, 12+1 = 12^1 = 13
for i=2, 12+2 = 12^2 = 14
for i=3, 12+3 = 12^3 = 15



/* c++ program to print count of values such 
that n+i = n^i */
#include <bits/stdc++.h> 
using namespace std; 

// function to count number of values less than 
// equal to n that satisfy the given condition 
int countValues(int n) 
{ 
	// unset_bits keeps track of count of un-set 
	// bits in binary representation of n 
	int unset_bits=0; 
	while (n) 
	{ 
		if ((n & 1) == 0) 
			unset_bits++; 
		n=n>>1; 
	} 

	// Return 2 ^ unset_bits 
	return 1 << unset_bits; 
} 

// Driver code 
int main() 
{ 
	int n = 12; 
	cout << countValues(n); 
	return 0; 
} 
