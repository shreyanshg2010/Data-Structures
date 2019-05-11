#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string str, int low, int high)
{
    return (low >= high) || (str[low] == str[high] &&
            isPalindrome(str, low + 1, high - 1));
}
bool isRotatedPalindrome(string str)
{
    int m = str.length();
    for (int i = 0; i < m; i++)
    {
        rotate(str.begin(), str.begin() + 1, str.end());
        if (isPalindrome(str, 0, m - 1))
            return true;
    }
    return false;
}
int main()
{
    string str;
    cin>>str;
    if (isRotatedPalindrome(str))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
