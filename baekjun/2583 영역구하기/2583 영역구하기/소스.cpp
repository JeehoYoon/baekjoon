#include <iostream>
using namespace std;

int arr[100][100];
int asw[10000];
int M, N, K;
int num;

//void quicksort(int st, int n) {
//	int i, j;
//	for (i = st+1, j = st + n - 1; i < j; i++, j--) {
//		if(asw[i]>asw[j])
//	}
//}
void sort(int st,int n){
	int ch;
	int idx;
	if (n) {
		int min = asw[st];
		idx = st;
		for (int i = st, j = 0; j < n; j++) {
			if (asw[i+j] < min) {
				idx = i+j;
				min = asw[i+j];
			}
		}
		ch = asw[st];
		asw[st] = asw[idx];
		asw[idx] = ch;
		sort(st + 1, n - 1);
	}
}

int dfs(int x, int y) {
	if (x < M&&x >= 0 && y < N&&y >= 0 && arr[x][y] == 3){
		arr[x][y] = 2;
		num++;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	}
	return num;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = 3;
	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				arr[x][y] = 1;
	}
	int m = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			num = 0;
			int k;
			if (k=dfs(i, j))
				asw[m++] = k;
		}
	cout << m << endl;
	sort(0, m);
	for (int i = 0; i < m; i++)
		cout << asw[i] <<" ";
	return 0;
}