#include <iostream>
using namespace std;
int arr[100][100];
int N, M;

int main() {
	cin >> N >> M;
	// -:45 |:124
	char x;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> x;
			arr[i][j] = (int)x;
		}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M - 1; j++)
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == 45) sum++;
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N - 1; i++)
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == 124) sum++;
	cout << N * M - sum;
	return 0;
}