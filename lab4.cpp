#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *cursors = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> cursors[i];
	direct(cursors, n, -1);
	cout << endl;
	reverse(cursors, n, -1);
	cout << endl;
	symmet(cursors, n, -1);
	cout << endl;
	return 0;
}
