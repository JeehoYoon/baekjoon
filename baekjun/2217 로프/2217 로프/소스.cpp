#include <iostream>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	int n, arr[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n,desc);
	int mx = 0;
	for (int i = 0; i < n; i++)
		if (mx < arr[i] * (i + 1)) mx = arr[i] * (i + 1);
	cout << mx;
	return 0;
}