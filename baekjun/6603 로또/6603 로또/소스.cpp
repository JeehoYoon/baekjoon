#include <iostream>
using namespace std;

int k[100];
int arr[100][13];
int zone[100][13];

void dfs(int m, int i) {
	if (i >= 0 && i < k[m]) {
		zone[m][i] = 1;
		dfs(m, i + 1);

		zone[m][i] = 0;
		dfs(m, i + 1);
	} 
	else if (i == k[m]) {
		int sum = 0;
		for (int j = 0; j < k[m]; j++) {
			sum += zone[m][j];
		}
		if (sum == 6) {
			for (int j = 0; j < k[m]; j++) {
				if (zone[m][j] == 1)
					cout << arr[m][j] <<" ";
			}
			cout << endl;
		}
	}
}

int main() {
	cin >> k[0];
	int j;
	for (j = 0; k[j] != 0; j++) {
		for (int i = 0; i < k[j]; i++)
			cin >> arr[j][i];
		cin >> k[j + 1];
	}
	for (int i = 0; i < j; i++) {
		dfs(i, 0);
		cout << endl;
	}
	return 0;
}