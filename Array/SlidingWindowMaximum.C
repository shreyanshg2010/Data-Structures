Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
Examples :

Input :
arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
k = 3 
Output :
3 3 4 5 5 5 6

Input :
arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
k = 4 
Output :
10 10 10 15 15 90 90



#include<stdio.h> 
  
void printKMax(int arr[], int n, int k) 
{ 
    int j, max; 
  
    for (int i = 0; i <= n-k; i++) 
    { 
        max = arr[i]; 
  
        for (j = 1; j < k; j++) 
        { 
            if (arr[i+j] > max) 
               max = arr[i+j]; 
        } 
        printf("%d ", max); 
    } 
} 
  
  
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3; 
    printKMax(arr, n, k); 
    return 0; 
}
