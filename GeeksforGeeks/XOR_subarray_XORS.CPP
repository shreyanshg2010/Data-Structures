Given an array of integers, we need to get total XOR of all subarray XORs where subarray XOR can be obtained by XORing all elements of it.

Examples :

Input : arr[] = [3, 5, 2, 4, 6]
Output : 7
Total XOR of all subarray XORs is,
(3) ^ (5) ^ (2) ^ (4) ^ (6)
(3^5) ^ (5^2) ^ (2^4) ^ (4^6)
(3^5^2) ^ (5^2^4) ^ (2^4^6)
(3^5^2^4) ^ (5^2^4^6) ^
(3^5^2^4^6) = 7     

Input : arr[] = {1, 2, 3}
Output : 2

Input : arr[] = {1, 2, 3, 4}
Output : 0



An efficient solution is based on the idea to enumerate all subarrays, we can count frequency of each element occurred totally in all subarrays, if the frequency of an element is odd then it will be included in final result otherwise not.

As in above example, 
3 occurred 5 times,
5 occurred 8 times,
2 occurred 9 times,
4 occurred 8 times,
6 occurred 5 times
So our final result will be xor of all elements which occurred odd number of times
i.e. 3^2^6 = 7

From above occurrence pattern we can observe that number at i-th index will have 
(i + 1) * (N - i) frequency. 



// C++ program to get total 
// xor of all subarray xors 
#include <bits/stdc++.h> 
using namespace std; 

// Returns XOR of all subarray xors 
int getTotalXorOfSubarrayXors(int arr[], 
							int N) 
{ 
	// initialize result by 0 
	// as (a XOR 0 = a) 
	int res = 0; 

	// loop over all elements once 
	for (int i = 0; i < N; i++) 
	{ 
		// get the frequency of 
		// current element 
		int freq = (i + 1) * (N - i); 

		// Uncomment below line to print 
		// the frequency of arr[i] 
		// cout << arr[i] << " " << freq << endl; 

		// if frequency is odd, then 
		// include it in the result 
		if (freq % 2 == 1) 
			res = res ^ arr[i]; 
	} 

	// return the result 
	return res; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {3, 5, 2, 4, 6}; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	cout << getTotalXorOfSubarrayXors(arr, N); 
	return 0; 
} 
