#include<cstring>
#include<iostream>

using namespace std;

int t, n, k, g[50][50], dp[51][51][5][2], dx[2] = { 1, 0 }, dy[2] = { 0, 1 }, ans = 0;

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

		memset(dp, 0, sizeof(dp));
		dp[1][0][0][0] = 1;
		dp[0][1][0][1] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j]) continue;
				for (int s = 0; s <= k; s++) {
					dp[i + dx[0]][j + dy[0]][s][0] += dp[i][j][s][0];
					dp[i + dx[1]][j + dy[1]][s + 1][1] += dp[i][j][s][0];
					dp[i + dx[1]][j + dy[1]][s][1] += dp[i][j][s][1];
					dp[i + dx[0]][j + dy[0]][s + 1][0] += dp[i][j][s][1];
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < 2; j++)
				ans += dp[n - 1][n - 1][i][j];

		cout << ans << "\n";
	}
}
