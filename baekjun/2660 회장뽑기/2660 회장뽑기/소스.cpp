#include <iostream>
using namespace std;

int arr[51][51];
int asw[51];
int rsw[51];

int dmin(int a, int b) {
	if (a <= b) return a;
	else return b;
}
int dmax(int a, int b) {
	if (a <= b) return b;
	else return a;
}
int main()
{
	int N, x, y;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] = 100;
	for (x = 0, y = 0; x != -1 && y != -1;) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= N; i++)
		arr[i][i] = 0;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				arr[i][j] = dmin(arr[i][j],arr[i][k] + arr[k][j]);
			}
	for (int i = 1; i <= N; i++) {
		int max = 0;
		for (int j = 1; j <= N; j++) {
			max = dmax(max, arr[i][j]);
		}
		asw[i] = max;
	}
	int m = 0;
	int min = N;
	for (int i = 1; i <= N; i++)
		min = dmin(min, asw[i]);
	for (int i = 1; i <= N; i++) {
		if (asw[i] == min)
			rsw[++m] = i;
	}
	
	cout << min << " " << m << endl;
	for (int i = 1; i <= m; i++)
		cout << rsw[i] << " ";


	return 0;
}