#include <iostream>
using namespace std;
int min(int a, int b);

int arr[3][1000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	for (int i = 1; i < N; i++) {
		arr[0][i] = min(arr[1][i - 1], arr[2][i - 1]) + arr[0][i];
		arr[1][i] = min(arr[0][i - 1], arr[2][i - 1]) + arr[1][i];
		arr[2][i] = min(arr[0][i - 1], arr[1][i - 1]) + arr[2][i];
	}
	cout << min(min(arr[0][N - 1], arr[1][N - 1]), arr[2][N - 1]);
}

int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}