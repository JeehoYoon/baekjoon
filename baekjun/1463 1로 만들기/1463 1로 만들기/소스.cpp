#include <iostream>
using namespace std;

int dp[1000001];

int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}
int main() {
	int N;
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (i % 6 == 0)
			dp[i] = min(dp[i / 2], min(dp[i / 3], dp[i - 1])) + 1;
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[N];
	return 0;
}