Make all numbers of an array equal
Given an array arr[], the task is to make all the array elements equal with the given operation. In a single operation, any element of the array can be either multiplied by 2 or by 3. If its possible to make all the array elements equal with the given operation then print Yes else print No.

Examples:

Input: arr[] = {50, 75, 100}
Output: Yes
{50 * 2 * 3, 75 * 2 * 2, 100 * 3} = {300, 300, 300}

Input: arr[] = {10, 14}
Output: No




// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function that returns true if all 
// the array elements can be made equal 
// with the given operation 
bool EqualNumbers(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) { 

		// Divide number by 2 
		while (a[i] % 2 == 0) 
			a[i] /= 2; 

		// Divide number by 3 
		while (a[i] % 3 == 0) 
			a[i] /= 3; 
	} 

	// Remaining numbers 
	for (int i = 1; i < n; i++) 
		if (a[i] != a[0]) { 
			return false; 
		} 

	return true; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 50, 75, 500 }; 

	int n = sizeof(a) / sizeof(a[0]); 

	if (EqualNumbers(a, n)) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
