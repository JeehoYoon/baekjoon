#include <iostream>
#include<queue>
using namespace std;
int arr[1002][1002];
int ans[1002][1002];
queue<int> x;
queue<int> y;
int h, w, n;
/*
void gogo(int i, int j) {
	x.pop();
	y.pop();
	if (i <= h + 1 && j <= w + 1) {
		int num = ans[i][j];
		ans[i + 1][j] += num / 2;
		ans[i][j + 1] += num / 2;
		if (num % 2 == 1)
			if (arr[i][j] == 1) ans[i][j+1]++;
			else ans[i+1][j]++;
		x.push(i);
		y.push(j + 1);
		x.push(i + 1);
		y.push(j);
	}
}*/
int main() {
	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];
	ans[1][1] = n;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (ans[i][j] % 2) {
				if (arr[i][j] == 1) ans[i][j+1]++;
				else ans[i+1][j]++;
			}
			ans[i + 1][j] += ans[i][j] / 2;
			ans[i][j + 1] += ans[i][j] / 2;
		}
	int i = 1, j = 1;
	while (i < h+1 && j < w+1) {
		if (arr[i][j] + (ans[i][j]) % 2 == 1) i++;
		else j++;
	}
	cout << i << " " << j;
	return 0;
}