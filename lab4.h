#include <iostream>

using namespace std;

int fRoot(const int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == -1)
			return i;
	}
	return -1;
}

void direct(const int* arr, int n, int father)
{
	if (father == -1)
		father = fRoot(arr, n);
	cout << father << " ";
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			direct(arr, n, i);
	}
}

void reverse(const int *arr, int n, int father)
{
	if (father == -1)
		father = fRoot(arr, n);
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			reverse(arr, n, i);
	}
	cout << father << " ";
}
