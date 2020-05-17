#include <iostream>
#include <stdio.h>
using namespace std;
int N, M;
int arr[1000][1000];

int miin(int a, int b, int c) {
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;
	return m;
}

int main() {
	cin >> N >> M;
	int mx = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &arr[i][j]);
			if (arr[i][j] == 1) mx = 1;
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++)
			if (arr[i][j] != 0) {
				arr[i][j] = miin(arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]) + 1;
				if (arr[i][j] > mx) 
					mx = arr[i][j];
			}
	cout << mx * mx;
	return 0;

}