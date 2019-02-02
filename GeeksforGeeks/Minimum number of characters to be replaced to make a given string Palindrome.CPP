Input: str = "geeks"
Output: 2
geeks can be converted to geeeg to make it palindrome
by replacing minimum characters.

Input: str = "ameba"
Output: 1
We can get "abeba" or "amema" with only 1 change. 
Among those two, "abeba" is lexicographically smallest.


// C++ Implementation of the above approach 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// character change required 

void change(string s) 
{ 

	// Finding the length of the string 
	int n = s.length(); 

	// To store the number of replacement operations 
	int cc = 0; 

	for(int i=0;i<n/2;i++) 
	{ 

		// If the characters at location 
		// i and n-i-1 are same then 
		// no change is required 
		if(s[i]== s[n-i-1]) 
			continue; 

		// Counting one change operation 
		cc+= 1; 

		// Changing the character with higher 
		// ascii value with lower ascii value 
		if(s[i]<s[n-i-1]) 
			s[n-i-1]= s[i] ; 
		else
			s[i]= s[n-i-1] ; 
	} 
	printf("Minimum characters to be replaced = %d\n", (cc)) ; 
	cout<<s<<endl; 
} 
// Driver code 
int main() 
{ 
string s = "geeks"; 
change((s)); 
return 0; 
} 
