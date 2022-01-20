#include<iostream>

using namespace std;

int n, m;

long long a[5001], b[10001], sa[10001], sb[10001], ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[x]++, b[y]++;
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			sa[i + j] += a[i] * a[j];
			sb[i + j] += b[i] * b[j];
		}
	}

	for (int i = 0; i <= 2 * m; i++) {
		ans += sa[i];
		cout << ans << "\n";
		ans -= sb[i];
	}
}
