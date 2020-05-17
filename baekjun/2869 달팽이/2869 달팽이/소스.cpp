#include <iostream>
using namespace std;
int main() {
	int a, b, v;
	cin >> a >> b >> v;
	int ans = (v - a) / (a - b);
	if ((v - a) % (a - b))
		ans++;
	cout << ans + 1;
	return 0;
}