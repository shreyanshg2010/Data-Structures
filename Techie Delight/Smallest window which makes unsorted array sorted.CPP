#include <iostream>
#include <climits>
using namespace std;

// Function to find the smallest window in the array sorting which will
// make the entire array sorted
void findSubarray(int arr[], int n)
{
	int leftIndex = -1, rightIndex = -1;

	// traverse from left to right and keep track of maximum so far
	int max_so_far = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (max_so_far < arr[i])
			max_so_far = arr[i];

		// find the last position that is less than the maximum so far
		if (arr[i] < max_so_far)
			rightIndex = i;
	}

	// traverse from right to left and keep track of minimum so far
	int min_so_far = INT_MAX;
	for (int i = n - 1; i >= 0; i--)
	{
		if (min_so_far > arr[i])
			min_so_far = arr[i];

		// find the last position that is more than the minimum so far
		if (arr[i] > min_so_far)
			leftIndex = i;
	}

	cout << "Sort array from index " << leftIndex << " to " << rightIndex;
}

// main function
int main()
{
	int arr[] = { 1, 3, 2, 7, 5, 6, 4, 8 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findSubarray(arr, n);

	return 0;
}
