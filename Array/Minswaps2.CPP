You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array  we perform the following steps:

i   arr [7, 1, 3, 2, 4, 5, 6]  swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
It took 5 swaps to sort the array.


Sample Input 0

4
4 3 1 2
Sample Output 0

3


int minimumSwaps(vector<int> arr) {
   
int n=arr.size();
int c=0;
for(int i=0;i<n;i++)
{
  if(arr[i]==i+1)
  continue;
  else
  {
      for(int j=i+1;j<n;j++)
      {
          if(arr[j]==i+1)
          {
              int x;
              x=arr[j];
              arr[j]=arr[i];
              arr[i]=x;
              c++;
              break;
          }
      }
  }
}
return c;

}
