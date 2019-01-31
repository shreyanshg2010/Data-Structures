Given a string S, write a program to title case every first letter of words in string.

Input:
The first line consists of an integer T i.e number of test cases. T testcases follow. The first and only line of each test case consists of a string S. 

Output:
For each testcase, in a new line, print the required output.

Constraints: 
1 <= T <= 100
1 <= |S| <= 1000

Example:
Input:
1
I love programming
Output:
I Love Programming


#include<iostream> 
#include<string>
using namespace std;

void upperCaseConversion(string str){
    for(int i=0;i<str.length();i++){
        if( (i==0 ||str[i-1] == ' ') && str[i]>='a' && str[i] <='z')
            cout<<char(str[i]-'a'+'A');
        else
            cout<<str[i];
    }
}

int main() {
	int T;
	string str;
	cin>>T;
	getline(cin,str);
	while(T--){
	    getline(cin,str);
	    upperCaseConversion(str);
	    cout<<endl;
	}
	return 0;
}
