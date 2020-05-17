#include <iostream>
using namespace std;

int arr[50][50];
int ans[50];
int N;

int man(int a, int b){
	if (a <= b) return b;
	else return a;
}

int serch(int n) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr[n][i] == 1) {
			ans[i] = 1;
			for (int j = 0; j < N; j++)
				if (arr[i][j] == 1)
					ans[j] = 1;
		}
	}
	ans[n] = 0;
	for (int i = 0; i < N; i++)
		if (ans[i] == 1) {
			ans[i] = 0;
			sum++;
		}
	return sum;
}

int main() {
	char s;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> s;
			if (s == 'N') arr[i][j] = 0;
			else if (s == 'Y') arr[i][j] = 1;
		}
	int maax = 0;
	for (int i = 0; i < N; i++) {
		maax = man(maax, serch(i));
	}
	cout << maax;
}