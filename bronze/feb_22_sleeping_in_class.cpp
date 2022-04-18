#include<iostream>

using namespace std;

int t, n, sum, a[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = n; i >= 1; i--) {
			if (sum % i == 0) {
				int quot = sum / i, cur = 0;
				for (int j = 0; j < n; j++) {
					cur += a[j];
					if (cur > quot) goto ok;
					if (cur == quot) cur = 0;
				}
				cout << n - i << '\n';
				break;
			}
			ok:;
		}
	}
}
