Input : a[] = {3, 4, 2, 7, 5, 8, 10, 6}  
              q = 2 
              index = 0, 
              index = 5
Output: 4 
        1 
Explanation: the next greater elements
to the right of 3(index 0) are 4, 7, 8, 
10. The next greater elements to the right
of 8(index 5) are 10.



O(1) SOLUTION


#include <bits/stdc++.h> 
using namespace std; 

// array to store the next greater element index 
void fillNext(int next[], int a[], int n) 
{ 
	// use of stl stack in c++ 
	stack<int> s; 

	// push the 0th index to the stack 
	s.push(0); 

	// traverse in the loop from 1-nth index 
	for (int i = 1; i < n; i++) { 

		// iterate till loop is empty 
		while (!s.empty()) { 

			// get the topmost index in the stack 
			int cur = s.top(); 

			// if the current element is greater 
			// then the top index-th element, then 
			// this will be the next greatest index 
			// of the top index-th element 
			if (a[cur] < a[i]) { 

				// initialize the cur index position's 
				// next greatest as index 
				next[cur] = i; 

				// pop the cur index as its greater 
				// element has been found 
				s.pop(); 
			} 

			// if not greater then break 
			else
				break; 
		} 

		// push the i index so that its next greatest 
		// can be found 
		s.push(i); 
	} 

	// iterate for all other index left inside stack 
	while (!s.empty()) { 

		int cur = s.top(); 

		// mark it as -1 as no element in greater 
		// then it in right 
		next[cur] = -1; 

		s.pop(); 
	} 
} 

// function to count the number of next greater numbers to the right 
void count(int a[], int dp[], int n) 
{ 
	// initializes the next array as 0 
	int next[n]; 
	memset(next, 0, sizeof(next)); 

	// calls the function to pre-calculate 
	// the next greatest element indexes 
	fillNext(next, a, n); 

	for (int i = n - 2; i >= 0; i--) { 

		// if the i-th element has no next 
		// greater element to right 
		if (next[i] == -1) 
			dp[i] = 0; 

		// Count of next greater numbers to right. 
		else
			dp[i] = 1 + dp[next[i]]; 
	} 
} 

// answers all queries in O(1) 
int answerQuery(int dp[], int index) 
{ 
	// returns the number of next greater 
	// elements to the right. 
	return dp[index]; 
} 

// driver program to test the above function 
int main() 
{ 
	int a[] = { 3, 4, 2, 7, 5, 8, 10, 6 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	int dp[n]; 

	// calls the function to count the number 
	// of greater elements to the right for 
	// every element. 
	count(a, dp, n); 

	// query 1 answered 
	cout << answerQuery(dp, 3) << endl; 

	// query 2 answered 
	cout << answerQuery(dp, 6) << endl; 

	// query 3 answered 
	cout << answerQuery(dp, 1) << endl; 

	return 0; 
} 
