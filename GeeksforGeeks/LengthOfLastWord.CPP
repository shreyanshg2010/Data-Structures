Input  : str = "Geeks For Geeks"
Output : 5
length(Geeks)= 5

Input : str = "Start Coding Here"
Output : 4
length(Here) = 4


#include <iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string A) {
    
    int count=0,i,n;
    n = A.length();
   
    while(A[n-1]==32)
     n=n-1;
    for(i=n-1;A[i]!=32 && i>=0;i--)
    {
        count++;
    }
    return count;
}
int main()
{   string str; 
    int x;
    getline (cin, str);
    x=lengthOfLastWord(str);
    cout<<x;
   
    return 0;
}
