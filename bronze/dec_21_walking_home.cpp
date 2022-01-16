#include<iostream>

using namespace std;

int t, n, k, g[50][50], ans = 0;

void dfs(int x, int y, int s, int d) {
	if (x >= n || y >= n || s > k || g[x][y]) return;

	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}

	if (d) {
		dfs(x, y + 1, s, 1);
		dfs(x + 1, y, s + 1, 0);
	}
	else {
		dfs(x + 1, y, s, 0);
		dfs(x, y + 1, s + 1, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c; cin >> c;
				g[i][j] = c == 'H';
			}
		}

		ans = 0;

		dfs(1, 0, 0, 0);
		dfs(0, 1, 0, 1);

		cout << ans << "\n";
	}
}
