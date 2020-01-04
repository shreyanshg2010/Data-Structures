#include<bits/stdc++.h> 
using namespace std; 
vector<string> getBooks (vector<string> str) 
{ // Write your code here 
unordered_set<string> s1; 
string list="a"; 
for(int i=0;i<str.size();i++){ 
if(str[i]!="?")
{ 
s1.insert(str[i]); 
} 
} 
for(int i=0;i<str.size();i++) 
{ if(str[i]=="?"){ 
while(s1.find(list)!=s1.end()){ 
int i=list.size()-1; while(i>=0 && list[i]=='z') i--; 
if(i==-1) list="a"+list; 
else list[i]++; i++; 
while(i<list.size()) list[i++]='a'; 
} 
str[i]=list; 
s1.insert(list); 
} } 
return str; 
} 
int main() { 
ios::sync_with_stdio(0); 
cin.tie(0); 
int N; 
cin >> N; 
vector<string> str(N); 
for(int i_str=0; i_str<N; i_str++) { 
cin >> str[i_str]; 
} 
vector<string> out_; 
out_ = getBooks(str); 
for(int i_out_=0; i_out_<out_.size(); i_out_++) { 
cout << out_[i_out_] << "\n"; 
} 
}
