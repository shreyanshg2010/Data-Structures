Given stream of integers,find median at every step

Sample Test Case:
Input: 5 10 15
Output: 5
        7.5
        10
        
Code:
#include<queue>
#include <iostream>
using namespace std;
void printMedians(double arr[],int n){
    priority_queue<double> s; //max heap
    priority_queue<double,vector<double>,greater<double>> g; //min heap
    double med=arr[0];
    s.push(arr[0]);
    cout<<med<<endl;
    for(int i=1;i<n;i++){
        double x=arr[i];
        if(s.size()>g.size()){
            if(x<med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            med=(s.top()+g.top())/2.0;
        }
        else if(s.size()==g.size()){
            if(x<med){
                s.push(x);
                med=(double)s.top();
            }
            else{
                g.push(x);
                med=(double)g.top();
            }
        }
        else{
            if(x>med){
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
            med=(s.top()+g.top())/2.0;
        }
        cout<<med<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    printMedians(arr,n);
}
