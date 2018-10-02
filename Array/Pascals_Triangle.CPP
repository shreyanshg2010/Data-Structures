#include <iostream>
#include<vector>
using namespace std;
vector <vector<int> > solve(int A) {
    vector <vector<int> >v;
    vector <int> temp;
    
    if(A<1)
        return v;
    
    temp.push_back(1);
    v.push_back(temp);
    
    if(A==1)
        return v;
        
    temp.push_back(1);
    v.push_back(temp);
    
    if(A==2)
        return v;
    
    for(int i=2;i<A;i++){
        vector <int> temp2;
        temp2.push_back(1);
        
        for(int j=1;j<i;j++){
            temp2.push_back(v[i-1][j-1]+v[i-1][j]);
        }
        
        temp2.push_back(1);
        
        v.push_back(temp2);
    }
    return v;}
int main()
{   int A;
    vector<vector<int>> B;
    cin>>A;
    B=solve(A);
    for(int i=0;i<A;i++){
        for(int j=0;j<=i;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}
