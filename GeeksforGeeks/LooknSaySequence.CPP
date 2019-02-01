The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.


// C++ program to find n'th term in look and say 
// sequence 
#include <bits/stdc++.h> 
using namespace std; 

// Returns n'th term in look-and-say sequence 
string countnndSay(int n) 
{ 
	// Base cases 
	if (n == 1)	 return "1"; 
	if (n == 2)	 return "11"; 

	// Find n'th term by generating all terms from 3 to 
	// n-1. Every term is generated using previous term 
	string str = "11"; // Initialize previous term 
	for (int i = 3; i<=n; i++) 
	{ 
		// In below for loop, previous character 
		// is processed in current iteration. That 
		// is why a dummy character is added to make 
		// sure that loop runs one extra iteration. 
		str += '$'; 
        cout<<str;
		int len = str.length(); 
        cout<<len;
		int cnt = 1; // Initialize count of matching chars 
		string tmp = ""; // Initialize i'th term in series 

		// Process previous term to find the next term 
		for (int j = 1; j < len; j++) 
		{ 
			// If current character does't match 
			if (str[j] != str[j-1]) 
			{ 
				// Append count of str[j-1] to temp 
				tmp += cnt + '0'; 

				// Append str[j-1] 
				tmp += str[j-1]; 

				// Reset count 
				cnt = 1; 
			} 

			// If matches, then increment count of matching 
			// characters 
			else cnt++; 
		} 

		// Update str 
		str = tmp; 
	} 

	return str; 
} 

// Driver program 
int main() 
{ 
	int N = 4; 
	cout << countnndSay(N) << endl; 
	return 0; 
} 
