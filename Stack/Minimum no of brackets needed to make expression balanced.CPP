Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3



#include<bits/stdc++.h> 
using namespace std; 


// Returns count of minimum reversals for making 
// expr balanced. Returns -1 if expr cannot be 
// balanced. 
int countMinReversals(string expr) 
{ 
	int len = expr.length(); 

	// length of expression must be even to make 
	// it balanced by using reversals. 
	if (len%2) 
	return -1; 

	// After this loop, stack contains unbalanced 
	// part of expression, i.e., expression of the 
	// form "}}..}{{..{" 
	stack<char> s; 
	for (int i=0; i<len; i++) 
	{ 
		if (expr[i]=='}' && !s.empty()) 
		{ 
			if (s.top()=='{') 
				s.pop(); 
			else
				s.push(expr[i]); 
		} 
		else
			s.push(expr[i]); 
	} 

	// Length of the reduced expression 
	// red_len = (m+n) 
	int red_len = s.size(); 

	// count opening brackets at the end of 
	// stack 
	int n = 0; 
	while (!s.empty() && s.top() == '{') 
	{ 
		s.pop(); 
		n++; 
	} 

	// return ceil(m/2) + ceil(n/2) which is 
	// actually equal to (m+n)/2 + n%2 when 
	// m+n is even. 
	return (red_len/2 + n%2); 
} 

// Driver program to test above function 
int main() 
{ 
string expr = "}}{{"; 
cout << countMinReversals(expr); 
return 0; 
} 
