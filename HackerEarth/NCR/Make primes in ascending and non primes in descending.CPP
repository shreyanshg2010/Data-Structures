#include<bits/stdc++.h>
using namespace std;
bool prime[100005];
void sieve(int n){
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
}
vector<long long int> PrimeAndComposite (vector<long long int> numbers) {
   // Write your code here
   sieve(100005);
   vector<long long int> v;
   vector<long long int> f;
   for(long long int i=0;i<numbers.size();i++){
       if(prime[numbers[i]]){
           f.push_back(numbers[i]);
       }
       else{
           v.push_back(numbers[i]);
       }
   }
   sort(v.begin(),v.end(),greater<long long int>());
   sort(f.begin(),f.end());
   long long int j=0,k=0;
   vector<long long int> s;
   for(long long int i=0;i<numbers.size();i++){
       if(prime[numbers[i]]){
           s.push_back(f[k]);
           k++;
           
       }
       else{
           s.push_back(v[j]);
           j++;
       }
   }
   return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int N;
    cin >> N;
    vector<long long int> numbers(N);
    for(int i_numbers=0; i_numbers<N; i_numbers++)
    {
    	cin >> numbers[i_numbers];
    }

    vector<long long int> out_;
    out_ = PrimeAndComposite(numbers);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
