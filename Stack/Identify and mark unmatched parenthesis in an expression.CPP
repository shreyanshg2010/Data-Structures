Input : ((a) 
Output : -10a1

Input : (a))
Output : 0a1-1

Input  : (((abc))((d)))))
Output : 000abc1100d111-1-1





// CPP program to mark balanced and unbalanced 
// parenthesis. 
#include <bits/stdc++.h> 
using namespace std; 

void identifyParenthesis(string a) 
{ 
	stack<int> st; 

	// run the loop upto end of the string 
	for (int i = 0; i < a.length(); i++) { 

		// if a[i] is opening bracket then push 
		// into stack 
		if (a[i] == '(') 
			st.push(i); 
		
		// if a[i] is closing bracket ')' 
		else if (a[i] == ')') { 

			// If this closing bracket is unmatched 
			if (st.empty()) 
				a.replace(i, 1, "-1"); 
			
			else { 

				// replace all opening brackets with 0 
				// and closing brackets with 1 
				a.replace(i, 1, "1"); 
				a.replace(st.top(), 1, "0"); 
				st.pop(); 
			} 
		} 
	} 

	// if stack is not empty then pop out all 
	// elements from it and replace -1 at that 
	// index of the string 
	while (!st.empty()) { 
		a.replace(st.top(), 1, "-1"); 
		st.pop(); 
	} 

	// print final string 
	cout << a << endl; 
} 

// Driver code 
int main() 
{ 
	string str = "(a))"; 
	identifyParenthesis(str); 
	return 0; 
} 
