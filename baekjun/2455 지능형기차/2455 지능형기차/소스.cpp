#include <iostream>
using namespace std;
int main() {
	int arr[4][2];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
	int ma = 0;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum = sum - arr[i][0] + arr[i][1];
		if (sum > ma) ma = sum;
	}
	cout << ma;
	return 0;
}