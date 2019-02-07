Given an array of n integers, The task is to find another integer x such that, if all the elements of the array are subtracted individually from the number x, then the sum of all the differences should add to 0. If any such integer exists, print the value of x, else print -1.

Example

Input: arr[] = {1, 2, 3}
Output: 2
Explanation: 
Substracting all the elements of arrays from 2,
The sum of difference is:
1 + 0 + (-1) = 0.



// C++ Program to find the 
// hidden number 

#include <iostream> 
using namespace std; 

	// Driver Code 

int main() { 
		// Getting the size of array 
		int n = 3; 

		// Getting the array of size n 
		int a[] = { 1, 2, 3 }; 

		// Solution 
		int i = 0; 

		// Finding sum of the array elements 
		long sum = 0; 
		for (i = 0; i < n; i++) { 
			sum += a[i]; 
		} 

		// Dividing sum by size n 
		long x = sum / n; 

		// Print x, if found 
		if (x * n == sum) 
			cout<<x<<endl; 
		else
			cout<<("-1")<<endl; 
	

	return 0; 
	// This code is contributed 
// by shashank 
} 
