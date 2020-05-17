#include <iostream>
using namespace std;

int arr[10000][2];
int maax(int a, int b, int c) {
	int maax;
	if (a >= b) maax = a;
	else maax = b;
	if (maax < c) maax = c;
	return maax;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0];
	arr[0][1] = arr[0][0];
	arr[1][1] = arr[0][1] + arr[1][0];
	for (int i = 2; i < n; i++)
		arr[i][1] = maax(arr[i - 1][1], arr[i - 2][1] + arr[i][0], arr[i - 3][1] + arr[i - 1][0] + arr[i][0]);
	cout << arr[n - 1][1];
	return 0;
}