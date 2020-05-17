#include <iostream>
#include <algorithm>
using namespace std;
int input[2][100001];
int siin[2][100001];
int sa[100001];
int N;


int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 1; n <= N; n++)
			cin >> input[0][n] >> input[1][n];
		for (int n = 1; n <= N; n++) {
			siin[0][n] = n;
			siin[1][input[0][n]] = input[1][n];
		}
		for (int n = 1; n <= N; n++)
			sa[n] = 0;
		int sum = 0;
		int min = 1;
		for (int i = N; i > 0; i--) {
			if (siin[1][i] == min) {
				sum++;
				sa[min] = 1;
				while (sa[min] == 1)
					min++;
			}
			else
				sa[siin[1][i]] = 1;
		}
		cout << sum <<endl;
	}
	return 0;
}
