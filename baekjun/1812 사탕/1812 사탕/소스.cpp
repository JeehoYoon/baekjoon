#include <iostream>
using namespace std;
int arr[1000];
int ans[1000];

int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int sum1 = 0;
	for (int i = 1; i < n; i += 2)
		sum1 += arr[i];
	ans[0] = sum / 2 - sum1;
	for (int i = 1; i < n; i++)
		ans[i] = arr[i - 1] - ans[i - 1];
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}