Given an array of n integers where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

Each student gets one packet.
The difference between the number of chocolates in packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} 
        m = 3
Output: Minimum Difference is 2
We have seven packets of chocolates and
we need to pick three packets for 3 students
If we pick 2, 3 and 4, we get the minimum
difference between maximum and minimum packet
sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} 
        m = 5
Output: Minimum Difference is 6
The set goes like 3,4,7,9,9 and the output 
is 9-3 = 6

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41,
                 30, 40, 28, 42, 30, 44, 48, 
                 43, 50} 
        m = 7
Output:  Minimum Difference is 10
We need to pick 7 packets. We pick 40, 41,
42, 44, 48, 43 and 50 to minimize difference
between maximum and minimum.




#include<iostream>
#include<algorithm>
using namespace std; 
int findMinDiff(int arr[], int n, int m) 
{ 
    // if there are no chocolates or number 
    // of students is 0 
    if (m==0 || n==0) 
        return 0; 
  
    // Sort the given packets 
    sort(arr, arr+n); 
  
    // Number of students cannot be more than 
    // number of packets 
    if (n < m) 
       return -1; 
  
    // Largest number of chocolates 
    int min_diff = INT_MAX; 
  
    // Find the subarray of size m such that 
    // difference between last (maximum in case 
    // of sorted) and first (minimum in case of 
    // sorted) elements of subarray is minimum. 
    int first = 0, last = 0; 
    for (int i=0; i+m-1<n; i++) 
    { 
        int diff = arr[i+m-1] - arr[i]; 
        if (diff < min_diff) 
        { 
            min_diff = diff; 
            first = i; 
            last = i + m - 1; 
        } 
    } 
    return (arr[last] - arr[first]); 
} 
  
int main() 
{ 
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 
                 30, 40, 28, 42, 30, 44, 48, 
                 43, 50}; 
    int m = 7;  // Number of students 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m); 
    return 0; 
} 
