Given strings s1 and s2, you need to find if s2 is a rotated version of the string s1. The strings are lowercase.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines for s1 and s2.

Output:
For each testcase, in a new line, you need to print 1 if s2 is a rotated version of s1; else print 0.

Constraints:
1 <= T <= 100
1 <= |s1|,|s2| <= 107

Example:
Input:
4
geeksforgeeks
forgeeksgeeks
mightandmagic
andmagicmigth
mushroomkingdom
itsamemario
geekofgeeks
geeksgeekof
Output:
1
0
0
1




CASE 1:
#include<bits/stdc++.h>
using namespace std;

// Check if s1 is a rotation of s2
void CheckStringsRotation(string s1, string s2)
{
    string s;

    // Append s2 to s2
    s = s2 + s2;
    
    // Check if s1 is substring of s
    int j = 0;
    int k = 0;
    
    // If sizes are different, not substring
    if(s1.size() != s2.size())
    {
        cout << "0" << endl;
        return;
    }
    
    // Find where first character match
    for(; j<s.size();)
    {
        if(s[j] != s1[0])
        {
            j++;
        }
        else
        {
            // Save current index to look in case this is not an entire match
            k = j;
            
            // Check if entire s1 is part of s
            for(int i=0; i<s1.size(), (j+i)<s.size(); i++)
            {
                if(s1[i] != s[j+i])
                {
                    break;
                }
                else if(i == (s1.size() - 1) )
                {
                    // Match found
                    cout << "1" << endl;
                    return;
                }
            }
            // Start on next j to check for entire string again
            j = k + 1;
        }
    }
    cout << "0" << endl;
    return;

}

int main() {
	//code
	int t;
	string s1, s2;
	
	cin >> t;
	while(t--)
	{
	    cin >> s1 >> s2;
	    CheckStringsRotation(s1, s2);
	}
	return 0;
}



SOLUTION 2:


#include<iostream>
using namespace std;
bool substr(string s, string str2){

   return (s.find(str2) != string::npos);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s1, s2;
	    cin>>s1;
	    cin>>s2;
	    string s;
	    if(s1.length()==s2.length()){
	    s=s1+s1;
	    
	    if(substr(s,s2) )
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;}
	    else 
	    cout<<"0"<<endl;
	    
	}
	return 0;
}


