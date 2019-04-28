Given a string s, change the string s according to the rules provided below:

Delete all the vowels from the string.
Insert # in front of all the consonants.
Change the case of all the letters of the string.
Examples:

Input : aBAcAba
Output :#b#C#B

Input :SunshinE!!
Output :#s#N#S#H#N!!

#include <bits/stdc++.h> 
using namespace std; 

string change_case(string a) 
{ 
	int l = a.length(); 
	
	for(int i = 0 ; i < l ; i++) 
	{ 
		if(a[i] >= 'a' && a[i] <= 'z') 
			a[i] = (char)(65 + 
				(int)(a[i] - 'a')); 
		else if(a[i] >= 'A' && a[i] <= 'Z') 
			a[i] = (char)(97 + 
				(int)(a[i] - 'A')); 
	} 
	
	return a; 
	
} 
string delete_vowels(string a) 
{ 
	string temp = ""; 
	int l = a.length(); 
	for(int i = 0 ; i < l ; i++) 
	{ 
		if(a[i] != 'a' && a[i] != 'e' && 
		a[i] != 'i' && a[i] != 'o' && 
		a[i] != 'u' && a[i] != 'A' && 
		a[i] != 'E' && a[i] != 'O' && 
		a[i] != 'U'&& a[i] != 'I') 
			temp += a[i]; 
	} 
	
	return temp; 
	
} 
string insert_hash(string a) 
{ 
	string temp = ""; 
	int l = a.length(); 
	
	for(int i = 0 ; i < l ; i++) 
	{ 
		// If character is not special 
		if((a[i] >= 'a' && a[i] <= 'z') || 
		(a[i] >= 'A' && a[i] <= 'Z')) 
			temp = temp + '#' + a[i]; 
		else
			temp = temp + a[i]; 
	} 
	
	return temp; 
	
} 
void transformSting(string a) 
{ 
	string b = delete_vowels(a); 
	string c = change_case(b); 
	string d = insert_hash(c); 

	cout << d; 
} 
int main() 
{ 
	string a = "SunshinE!!"; 
	
	// Calling function 
	transformSting(a); 
	
	return 0; 
} 
