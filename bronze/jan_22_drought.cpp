#include<iostream>

using namespace std;

int t, n, a[100000], dt[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		if (n == 1) { cout << "0\n"; continue; }

		long long ans = 0;

		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1]) {
				int diff = a[i] - a[i - 1];
				ans += diff * 2;
				a[i + 1] -= diff;
				a[i] = a[i - 1];
			}
		}

		if (a[n - 1] > a[n - 2]) { cout << "-1\n"; continue; }

		for (int i = n - 2; i > 0; i--) {
			if (a[i] > a[i + 1]) {
				int diff = a[i] - a[i + 1];
				ans += diff * 2;
				a[i - 1] -= diff;
				a[i] = a[i + 1];
			}
		}

		if (a[0] > a[1] || a[0] < 0) { cout << "-1\n"; }
		else cout << ans << "\n";
	}
}
