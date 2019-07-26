Input:
5
5 6 7 8 4
Output:
12
Explanation:
multiple of 1:{5,6,7,8,4}
multiple of 2:{6,4,8}
multiple of 3:{6}
multiple of 4:{4,8}
multiple of 5:{5}
So,5+3+1+2+1=12


#include <bits/stdc++.h> 
using namespace std; 
int* ans = NULL; 
void countSieve(int arr[], int n) 
{ 
	int MAX = *max_element(arr, arr + n); 

	int cnt[MAX + 1]; 
	ans = new int[MAX + 1]; 
	memset(cnt, 0, sizeof(cnt)); 
	memset(ans, 0, (MAX + 1) * sizeof(int)); 
	for (int i = 0; i < n; ++i) 
		++cnt[arr[i]]; 
	for (int i = 1; i <= MAX; ++i) 
		for (int j = i; j <= MAX; j += i) 
			ans[i] += cnt[j]; 
	return; 
} 

int countMultiples(int k) 
{ 
	return ans[k]; 
} 

int main() 
{ 
	int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int a[n],sum=0;
	countSieve(arr, n); 
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        sum=sum+countMultiples(a[i]);
    }
    cout<<sum;
    
	return 0; 
} 
