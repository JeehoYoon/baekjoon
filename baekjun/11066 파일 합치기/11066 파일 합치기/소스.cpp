#include <iostream>
using namespace std;

int arr[500][500];
int answer[1000];

int sum(int i, int j) {
	int ssum = 0;
	for (int a = i; a <= j; a++)
		ssum += arr[a][a];
	return ssum;
}

int main() {
	int T,N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> arr[n][n];
		}
		for (int i = 0; i < N - 1; i++)
			arr[i][i + 1] = arr[i][i] + arr[i + 1][i + 1];
		for (int i = 2; i < N; i++) {
			for (int j = 0; j < N-i; j++) {
				long long min=99996999999999999;
				for (int k = 0; k < i; k++) {
					int sum;
					if (k == 0)
						sum = arr[j + 1][j + i];
					else if (k == i - 1)
						sum = arr[j][j + i - 1];
					else 
						sum = arr[j][j + k] + arr[j + k + 1][j + i];
					if (sum < min) min = sum;
				}
				arr[j][j + i] = min + sum(j, j + i);
			}
		}
		answer[t] = arr[0][N - 1];
	}
	for (int i = 0; i < T; i++)
		cout << answer[i] << endl;
	return 0;
}