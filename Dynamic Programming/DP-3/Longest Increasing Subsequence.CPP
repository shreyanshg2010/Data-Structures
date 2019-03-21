Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}



#include <bits/stdc++.h>
using namespace std;
int lis(int arr[],int n){
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;}}
    return *max_element(lis,lis+n);}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<lis(arr,n);}

