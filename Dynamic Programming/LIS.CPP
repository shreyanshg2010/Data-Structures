#include<bits/stdc++.h>
using namespace std;
int CeilIndex(vector<int>v,int l,int r,int key){
   while(r-l>1){
       int m=l+(r-l)/2;
       if(v[m]>=key)
         r=m;
       else
         l=m;
        }
        return r;
}
int LongestIncreasing(vector<int>v){
 if(v.size()==0) return 0;
 vector<int>tail(v.size(),0);
 int len=1;
 tail[0]=v[0];
 for(size_t i=1;i<v.size();i++){
   if(v[i]<tail[0]) tail[0]=v[i];
   if(v[i]>tail[len-1]) tail[len++]=v[i];
   else tail[CeilIndex(tail,-1,len-1,v[i])]=v[i];
   }
   return len;
}
int main(){
vector<int>v{2,3,5,4,6};
cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasing(v);
return 0;
}
         
