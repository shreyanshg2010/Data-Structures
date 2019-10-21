Find prime numbers between an intervaland then find largest prime factor which is less than or equal to K
Input:
1
3 2 20
Ouput:
7
Explanation:
The prime numbers between 2 to 20 are 2 3 5 7 11 13 17 19 
Then we check for the prime
(2-1)=1 which has largest prime factor as 1 that is less than K=3
(3-1)=2 which has largest prime factor as 2 that is less than K=3
(5-1)=4 which has largest prime factor as 2 that is less than K=3
(7-1)=6 which has largest prime factor as 3 that is less than K=3
(11-1)=10 which has largest prime factor as 5 that is not less than K=3(so not considerd)
(13-1)=12 which has largest prime factor as 3 that is less than K=3
(17-1)=16 which has largest prime factor as 2 that is less than K=3
(19-1)=18 which has largest prime factor as 3 that is less than K=3
So count is 7 as other are satisfying the constraints

#include <bits/stdc++.h> 
using namespace std; 
long long maxPrimeFactors(long long n) 
{ 
	long long maxPrime = -1; 
	while (n % 2 == 0) { 
		maxPrime = 2; 
		n >>= 1;
	} 
	for (int i = 3; i <= sqrt(n); i += 2) { 
		while (n % i == 0) { 
			maxPrime = i; 
			n = n / i; 
		} 
	} 
	if (n > 2) 
		maxPrime = n; 

	return maxPrime; 
} 

int main() 
{ 
	long long a, b, i, j,k,x, flag,tc;
    cin >> tc;
    while(tc--){
        int s=0;
    cin >> k;
	cin >> a; 
	cin >> b; 
	for (i = a; i <= b; i++) 
	{  
		if (i == 1 || i == 0) 
			continue; 
		flag = 1; 

		for (j = 2; j <= sqrt(i); ++j) 
		{ 
			if (i % j == 0) 
			{ 
				flag = 0; 
				break; 
			} 
		} 
        if (flag == 1){ 
			//cout << i << " ";
            x=maxPrimeFactors(i-1);
            if(x<=k){
                s++;
        }
            
	} 
    }
        cout<<s;
    }

	return 0; 
} 
