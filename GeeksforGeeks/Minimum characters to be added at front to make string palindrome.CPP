Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.



// C++ program for getting minimum character to be 
// added at front to make string palindrome 
#include<bits/stdc++.h> 
using namespace std; 

// function for checking string is palindrome or not 
bool ispalindrome(string s) 
{ 
	int l = s.length(); 
	int j; 
	
	for(int i = 0, j = l - 1; i <= j; i++, j--) 
	{ 
		if(s[i] != s[j]) 
			return false; 
	} 
	return true; 
} 

// Driver code 
int main() 
{ 
	string s = "AAAACAAA"; 
	int cnt = 0; 
	int flag = 0; 
	
	while(s.length()>0) 
	{ 
		// if string becomes palindrome then break 
		if(ispalindrome(s)) 
		{ 
			flag = 1; 
			break; 
		} 
		else
		{ 
		cnt++; 
		
		// erase the last element of the string 
		s.erase(s.begin() + s.length() - 1); 
		} 
	} 
	
	// print the number of insertion at front 
	if(flag) 
		cout << cnt; 
} 
