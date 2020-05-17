#include<iostream>
using namespace std;

int arr[101][3];

int main() {
	int N, st, fin, m, a, b;
	cin >> N >> st >> fin >> m;
	for (int i = 1; i <= N; i++) {
		arr[i][0] = -1; //ºÎ¸ğ
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[b][0] = a;
		arr[b][1] = 1;
	}
	b = st;
	for (int n = 0;; n++) {
		arr[b][2] = n;
		arr[b][1] = 2;
		if (arr[b][0] == -1)
			break;
		b = arr[b][0];
	}
	a = fin;
	int fail = -1;
	for (int i=0;;i++) {
		if (arr[a][1] == 2)
		{
			cout << arr[a][2] + i;
			return 0;
		}
		if (arr[a][0] == -1)
		{
			cout << fail << endl;
			return 0;
		}
		a = arr[a][0];
	}
	return 0;
}