#include <bits/stdc++.h>
using namespace std;

 int firstIndex(vector<int> arr, int low, int high, int n, int target)
{
  if(high>=low){
    int mid = low+(high-low)/2;
    if((mid==0 || target>arr[mid-1]) && arr[mid]==target){
      return mid;
    }
    else if(target>arr[mid])
      return firstIndex(arr,mid+1,high,n,target);
    else
      return firstIndex(arr,low,mid-1,n,target);
  }
  return -1;
      
}
 int lastIndex(vector<int> arr, int low, int high, int n, int target)
{
  if(high>=low){
    int mid = low+(high-low)/2;
    if((mid==n-1 || target<arr[mid+1]) && arr[mid]==target){
      return mid;
    }
    else if(target>arr[mid])
      return lastIndex(arr,mid+1,high,n,target);
    else
      return lastIndex(arr,low,mid-1,n,target);
  }
  return -1;
      
}
  
  int freqElements(vector<int> arr, int target){
  int n = arr.size();
  int low = 0;
  int high = n-1;
  int firstIn = firstIndex(arr,low,high,n, target);
  if(firstIn==-1){
    return 0;
  }
  int lastIn = lastIndex(arr,low,high,n,target);
  return lastIn-firstIn+1;
  
}

// To execute C++, please define "int main()"
int main() {
  
  int n, target;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  cout<<freqElements(arr,target);
  
}

 
