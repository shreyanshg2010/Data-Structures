Input:aman
Output:nama 

METHOD-1:

#include <iostream>
#include <string>
using namespace std;
string reverse(string s)
{
	string rev;
	for (int i = s.size() - 1; i >= 0; i--) {
		rev = rev.append(1, s[i]);
	};

	return rev;
}
int main()
{
	string s;
    cin>>s;
	s = reverse(s);
	cout << s;
	return 0;
}



METHOD-2:(using iterators)

#include <iostream>
#include <string>
using namespace std;

// Function to reverse a string
string reverse(string const &s)
{
	string rev;

	std::string::const_reverse_iterator it = s.crbegin();
	while (it != s.crend()) {
		rev = rev.append(1, *(it++));
	};

	return rev;
}

// main function
int main()
{
	std::string s("Reverse std::string");

	s = reverse(s);
	cout << s;

	return 0;
}


METHOD-3:(Using for_each)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to reverse a string
string reverse(string const &s)
{
	string rev;
	for_each(s.crbegin(), s.crend(), [&rev] (char const &c) {
				rev = rev.append(1, c);
			});

	return rev;
}

// main function
int main()
{
	std::string s("Reverse std::string");

	s = reverse(s);
	cout << s;

	return 0;
}

METHOD-4:(Using string constructor)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to reverse a string
string reverse(string const &s)
{
	string rev(s.rbegin(), s.rend());
	return rev;
}

// main function
int main()
{
	std::string s("Reverse std::string");

	s = reverse(s);
	cout << s;

	return 0;
}
