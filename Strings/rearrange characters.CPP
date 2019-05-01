#include<bits/stdc++.h>
using namespace std;
struct Key{
    int freq;
    char ch;
    bool operator<(const Key &k) const
    {
        return freq<k.freq;
    }
};
void rearrange(string str){
    int n=str.length();
    int count[26]={0};
    for(int i=0;i<n;i++)
        count[str[i]-'a']++;
    priority_queue<Key>pq;
    for(char c='a';c<='z';c++){
        if(count[c-'a']){
            pq.push(Key{count[c-'a'],c});
        }
    }
    str="";
    Key prev{-1,'#'};
    while(!pq.empty()){
        Key k=pq.top();
        pq.pop();
        str=str+k.ch;
        if(prev.freq>0)
            pq.push(prev);
        (k.freq)--;
        prev=k;
    }
    if(n!=str.length())
        cout<<"not valid string";
    else
        cout<<str;
}
int main(){
    string str;
    cin>>str;
    rearrange(str);
    return 0;
}
    
