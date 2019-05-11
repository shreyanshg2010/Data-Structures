#include <iostream>
using namespace std;
void recurse(int arr[], string out, int i, int n, int k)
{
	if (k > n)
		return;
	if (k == 0) {
		cout << out << endl;
		return;
	}
	for (int j = i; j < n; j++)
	{
		recurse(arr, out + " " + to_string(arr[j]) , j + 1, n, k - 1);
	}
}

// Find all distinct combinations of given length
int main()
{
	int arr[] = { 1, 2, 3 };
	int k = 2;
	int n = sizeof(arr) / sizeof(arr[0]);
	recurse(arr, "", 0, n, k);
	return 0;
}
