#include <iostream>
using namespace std;

int arr[15][2];
int mmax;
int N;
int test;

void dfs(int i,int sum) {
	if (i < N) {
		if (sum > mmax)
			mmax = sum;
		dfs(i + arr[i][0], sum + arr[i][1]);
		dfs(i + 1, sum);
	}
	else if(i==N)
		if (sum > mmax)
			mmax = sum;
}

int main() {
	mmax = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1];
	dfs(0, 0);
	cout << mmax;
	return 0;
}