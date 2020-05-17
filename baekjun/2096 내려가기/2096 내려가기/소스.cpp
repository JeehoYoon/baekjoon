#include <iostream>
using namespace std;
int N;
int big[3][2];
int sma[3][2];
int miin(int a, int b) {
	if (a <= b) return a;
	else return b;
}
int maax(int a, int b) {
	if (a <= b) return b;
	else return a;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> big[0][1] >> big[1][1] >> big[2][1];
		for (int j = 0; j < 3; j++)
			sma[j][1] = big[j][1];
		big[0][1] = maax(big[0][0] + big[0][1], big[1][0] + big[0][1]);
		big[1][1] = maax(big[0][0] + big[1][1], maax(big[1][0] + big[1][1], big[2][0] + big[1][1]));
		big[2][1] = maax(big[1][0] + big[2][1], big[2][0] + big[2][1]);
		sma[0][1] = miin(sma[0][0] + sma[0][1], sma[1][0] + sma[0][1]);
		sma[1][1] = miin(sma[0][0] + sma[1][1], miin(sma[1][0] + sma[1][1], sma[2][0] + sma[1][1]));
		sma[2][1] = miin(sma[1][0] + sma[2][1], sma[2][0] + sma[2][1]);
		for (int j = 0; j < 3; j++) {
			big[j][0] = big[j][1];
			sma[j][0] = sma[j][1];
		}
	}
	cout << maax(big[0][1], maax(big[1][1], big[2][1])) <<" ";
	cout << miin(sma[0][1], miin(sma[1][1], sma[2][1]));
	return 0;
}