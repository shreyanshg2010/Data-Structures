Given a list of items and their values. The task is to find top k items with the highest value. It is possible that two items have the same value, in that case item whose name comes first (lexicographically) will be given higher priority.

Examples:

Input: items[] = {Bat, Gloves, Wickets, Ball}, values[] = {100, 50, 200, 100}
k = 2

Output: Wickets Ball
Wickets has the highest value.
Bat, Ball has the same value but Ball comes first lexicographically.




// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Boolean Comparator Function 
// to compare two pairs of item-value 
bool comp(pair<string, int> A, pair<string, int> B) 
{ 
	// Compare the name if the values are equal 
	if (A.second == B.second) 
		return A.first < B.first; 

	// Else compare values 
	return A.second > B.second; 
} 

// Driver code 
int main() 
{ 
	int k = 2; 
	int n = 3; 

	// Store data in a vector of Item-Value Pair 
	vector<pair<string, int> > items; 

	// inserting items-value pairs in the vector 
	items.push_back(make_pair("Bat", 100)); 
	items.push_back(make_pair("Gloves", 50)); 
	items.push_back(make_pair("Wickets", 200)); 
	items.push_back(make_pair("Ball", 100)); 

	// Sort items using Inbuilt function 
	sort(items.begin(), items.end(), comp); 

	// Print top k values 
	// or if n is less than k 
	// Print all n items 
	for (int i = 0; i < min(n, k); ++i) { 
		cout << items[i].first << '\n'; 
	} 

	return 0; 
} 
