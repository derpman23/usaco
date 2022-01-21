#include<cstring>
#include<iostream>

using namespace std;

typedef long long ll;

int n, g[500][500], a[500][500], b[500];

ll count() {
	ll res = 0;

	for (int i = 0; i < n; i++) {
		memset(b, 1, sizeof(b));
		for (int j = i; j < n; j++) {
			ll cnt = 0;
			for (int k = 0; k < n; k++) {
				b[k] &= a[j][k];
				if (b[k]) res += ++cnt;
				else cnt = 0;
			}
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			a[i][j] = g[i][j] >= 100;
		}
	}

	ll ans = count();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = g[i][j] > 100;

	ans -= count();

	cout << ans << "\n";
}
