Input-
7 
5 2 0 3 6 1 4
Output-
4
Explanation-
0->5
5->1
1->2
2->0 max1:4
3->3 max1:1
4->6
6->4 max1:2
max(max1):4


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int s(vector<int> a){
    int l=a.size(),max=0;
    int occ[l];
    for(int i=0;i<l;i++){
    occ[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        if(occ[i]==1)
            continue;
        else{
            occ[i]=1;
            int s=a[i];
            int c=1;
            while(s!=i)
            {
            c++;
                occ[s]=1;
                s=a[s];
            }
            if(c>max)
                max=c;
        }
    }
    return max;
}          



int main(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<s(a);
    return 0;
}
