#include <iostream>
using namespace std;
int main() {
	int k = 0;
	long long n;
	int arr[10];
	cin >> n;
	for (; n > 0; k++) {
		arr[k] = n % 10;
		n /= 10;
	}
	long long a, b;
	int flag = 0;
	for (int i = 1; i < k; i++) {
		a = 1;
		b = 1;
		for (int j = 0; j < i; j++)
			a *= arr[j];
		for (int j = i; j < k; j++)
			b *= arr[j];
		if (a == b) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) cout << "YES" << endl;
	else if (flag == 0) cout << "NO" << endl;
	return 0;
}