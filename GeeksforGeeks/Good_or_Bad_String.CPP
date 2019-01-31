In this problem, a String S is composed of lowercase alphabets and wildcard characters i.e. '?'. Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given String on the basis of following rules:

If there are more than 3 consonants together or more than 5 vowels together, the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

NOTE: String is considered as "BAD" if the above condition is satisfied even once. Else it is "GOOD" and the task is to make the string "BAD".

Input:
The first line consists of an integer T i.e number of test cases. T testcases follow. The first and only line of each test case consists of a string S. 

Output:
For each testcase, in a new line, print "1"  if string is GOOD, else print "0".

Constraints: 
1 <= T <= 100
1 <= |S| <= 100

Example:
Input:
2
aeioup??
bcdaeiou??
Output:
1
0




#include<cstring>
#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    char arr[100];
	    cin>>arr;
	    int flag=0;int consonent=0,vowel=0;
	    for(int i=0;i<strlen(arr);i++){
	        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
	            vowel++;
	            consonent=0;
	            
	        }
	        else if(arr[i]=='?'){
	            vowel++;
	            consonent++;
	            
	        }
	        else {
	            consonent++;
	            vowel=0;
	            
	        }
	        if(vowel>5 || consonent>3){
	            cout<<0<<endl;
	            flag=1;
	            break;}
	    }
	    if(flag==0)
	    cout<<1<<endl;
	    //cout<<arr<<endl;
	}
	return 0;
}
