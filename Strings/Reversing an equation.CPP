#include <bits/stdc++.h> 
using namespace std; 
string reverseEquation(string s) 
{ 
	string result; 
	int j = 0; 
	for (int i = 0; i < s.length(); i++) { 
		if (s[i] == '+' || s[i] == '-' || 
			s[i] == '/' || s[i] == '*') { 
			result.insert(result.begin(), 
				s.begin() + j, s.begin() + i); 
			j = i + 1; 
			result.insert(result.begin(), s[i]); 
		} 
	} 
	result.insert(result.begin(), s.begin() + j, 
									s.end()); 
	return result; 
} 
int main() 
{ 
	string s = "a+b*c-d/e"; 
	cout << reverseEquation(s) << endl; 
	return 0; 
} 
