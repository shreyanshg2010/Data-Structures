#include <iostream>
#include <string>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n < 0 || sum < 0)
		return false;
	bool include = subsetSum(arr, n - 1, sum - arr[n]);
	bool exclude = subsetSum(arr, n - 1, sum);
	return include || exclude;
}
bool partition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	sum += arr[i];
	return !(sum & 1) && subsetSum(arr, n - 1, sum/2);
}
int main()
{
	int arr[] = { 7, 3, 1, 5, 4, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	if (partition(arr, n))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
