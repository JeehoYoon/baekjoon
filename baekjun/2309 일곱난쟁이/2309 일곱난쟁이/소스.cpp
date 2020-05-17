#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int ar[9];
int allsum() {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += ar[i];
	return sum;
}

int main() {
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr, arr + 9);
	
	for (int i = 0; i < 9; i++)
		ar[i] = arr[i];

	for(int i=0;i<9;i++)
		for (int j = i + 1; j < 9 && j != i; j++) {
			ar[i] = 0;
			ar[j] = 0;
			if (allsum() == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << ar[k] << endl;
				}
				return 0;
			}
			else {
				ar[i] = arr[i];
				ar[j] = arr[j];
			}
		}
}