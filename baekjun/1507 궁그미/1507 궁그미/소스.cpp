#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define inf 999999;
using namespace std;
int ans[20][20];
int arr1[20][20];
int arr2[20][20];
int N;

long long same() {
	long long num = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			num += (arr2[i][j] - ans[i][j]);
	return num;
}
void floy() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr2[i][j] = arr1[i][j];
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (arr2[i][j] > arr2[i][k] + arr2[k][j])
					arr2[i][j] = arr2[i][k] + arr2[k][j];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ans[i][j];
	int sum = 0;
	vector<tuple<int, int, int> > v;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			v.push_back(make_tuple(ans[i][j], i, j));
			sum += ans[i][j];
		}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr1[i][j] = ans[i][j];
	floy();
	if (same() != 0) {
		cout << -1;
		return 0;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		int x = get<1>(v[i]);
		int y = get<2>(v[i]);
		arr1[x][y] = inf;
		arr1[y][x] = inf;
		floy();
		if (arr2[x][y] > ans[x][y]) {
			arr1[x][y] = ans[x][y];
			arr1[y][x] = ans[x][y];
		}
		else sum -= ans[x][y];
	}
	cout << sum;
	return 0;
}
