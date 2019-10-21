Minium number of letters to be deleted to obtain a word in which every letter occurs uniquely
Input1-
aaaabbbb
Output1-
1(if we delete one a or one b then there will be unique number of letters that is 3 and 4)

Input2-
aaaa
Output2-
0

Input3-
ccaaffddecee
Output3-
6


#include <bits/stdc++.h> 
using namespace std; 
void printCharWithFreq(string str)
{
	int n = str.size(),count=0;  
	int freq[26]; 
	memset(freq, 0, sizeof(freq)); 
	for (int i = 0; i < n; i++) 
		freq[str[i] - 'a']++; 
    vector<int> a;
    for(int i=0;i<26;i++)
    {
        if(freq[i])
        a.push_back(freq[i]);
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==1)
        {
            count=count+(a.size()-i-1);
            break;
        }
        int e=a[i],ec=1,j=i+1;
        while(a[j]==e)
        {
            ec++;
            j++;
        }
        count=count+ec-1;
        for(int k=j-1;k>i;k--)
        {
            a[k]=a[k]-1;
        }
    }
    cout<<count;
	/*for (int i = 0; i < n; i++) { 
		if (freq[str[i] - 'a'] != 0) { 
			cout << str[i] << freq[str[i] - 'a'] << " "; 
			freq[str[i] - 'a'] = 0; 
		} 
	} */
} 
int main() 
{ 
	string str = "example"; 
	printCharWithFreq(str); 
	return 0; 
} 
