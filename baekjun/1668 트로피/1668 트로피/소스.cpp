#include <iostream>
using namespace std;
int arr[50];
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int m = 0;
	int n = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > m) {
			m = arr[i];
			n++;
		}
	}
	cout << n << endl;
	m = 0;
	n = 0;
	for (int i = N-1; i >=0; i--) {
		if (arr[i] > m) {
			m = arr[i];
			n++;
		}
	}
	cout << n << endl;
}