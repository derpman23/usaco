#include<iostream>
#include<numeric>

using namespace std;

int n, dt[100002], ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> dt[i];

	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		dt[i] -= t;
	}

	for (int i = 0; i <= n; i++)
		ans += abs(dt[i] - dt[i + 1]) ;

	cout << ans / 2 << "\n";
}
