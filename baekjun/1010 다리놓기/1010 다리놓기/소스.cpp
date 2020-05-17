#include <iostream>
using namespace std;

long long arr[31][31];

void full_num(int x, int y) {
	long long sum = 0;
	for (int i = y - 1; i >= x - 1; i--)
		sum += arr[x - 1][i];
	arr[x][y] = sum;
}

int main() {
	for (int i = 1; i <= 30; i++) {
		arr[1][i] = i;
		arr[i][i] = 1;
	}
	for (int i = 2; i <= 30; i++)
		for (int j = i + 1; j <= 30; j++)
			full_num(i, j);
	int T;
	cin >> T;
	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		cout << arr[x][y] << endl;
	}
	return 0;
}