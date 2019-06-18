INPUT:
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1

OUTPUT:
3

In the above example, third row contains maximum number of 1's ie, four 1's



#include <bits/stdc++.h>
#define m 4
#define n 4
using namespace std;
int maxOnes(int arr[m][n])
{
	int row = 0;
	int index = INT_MAX;
	int j = n -1 ;
	for (int i = 0; i < m; ++i)
	{
		while(arr[i][j]==1 && j>=0) 
		{
		    j= j-1;
		    row = i;
		}
	}
	cout<<"The row having maximum ones is "<<row<<endl;
	

}
int main()
{
	int arr[m][n] = {{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,1,1,1}};
	maxOnes(arr);
	return 0;
}
