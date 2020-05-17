#include <iostream>
using namespace std;
int arr[100][100];
int N;
int miin(int a, int b) {
	if (a <= b) return a;
	else return b;
}
int main() {
	cin >> N;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 0) arr[i][j] = 101;
		}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				arr[i][j] = miin(arr[i][j], arr[i][k] + arr[k][j]);
			}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 101) arr[i][j] = 0;
			else arr[i][j] = 1;
			cout<< arr[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}