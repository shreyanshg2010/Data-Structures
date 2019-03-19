#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if the input string matches
// with a given wildcard pattern
bool isMatch(string str, int n, string pattern, int m)
{
	// end of pattern is reached
	if (m == pattern.size())
	{
		// return true only if end of input string is also reached
		return n == str.size();
	}

	// if the input string reaches its end, return when the
	// remaining characters in the pattern are all '*'
	if (n == str.size())
	{
		for (int i = m; i < pattern.size(); i++)
			if (pattern[i] != '*')
				return false;

		return true;
	}

	// if current wildcard character is '?' or current character in
	// pattern is same as current character in the input string
	if (pattern[m] == '?' || pattern[m] == str[n])
	{
		// move to next character in the pattern and the input string
		return isMatch(str, n + 1, pattern, m + 1);
	}

	// if current wildcard character is '*'
	if (pattern[m] == '*')
	{
		// move to next character in the input string or
		// ignore '*' and move to next character in the pattern
		return isMatch(str, n + 1, pattern, m) ||
			   isMatch(str, n, pattern, m + 1);
	}

	// we reach here when current character in the pattern is not a
	// wildcard character and it doesn't matches with the current
	// character in the input string
	return false;
}

// Check if a string matches with a given wildcard pattern
bool isMatch(string str, string pattern)
{
	return isMatch(str, 0, pattern, 0);
}

// main function
int main()
{
	cout << boolalpha;

	cout << isMatch("XYXZZXY", "X***Y") << endl;	// true
	cout << isMatch("XYXZZXY", "X*ZZ??") << endl;   // true
	cout << isMatch("XYXZZXY", "*X*X?") << endl;	// true
	cout << isMatch("XYXZZXY", "X***X") << endl;	// false
	cout << isMatch("XYXZZXY", "*") << endl;		// true

	return 0;
}
