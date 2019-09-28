#include<iostream>
using namespace std;
int phi(int n) 
{ 
	int result = n; 
	for (int p = 2; p * p <= n; ++p) { 
		if (n % p == 0) { 
			while (n % p == 0) 
				n /= p; 
			result -= result / p; 
		} 
	} 
	if (n > 1) 
		result -= result / n; 
	return result; 
}  
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
	int n,i; 
    cin>>n;
	for (i= 1; i <= n; i++) 
        cout<<phi(i)<<" "; 
    cout<<"\n";}
	return 0; 
} 
