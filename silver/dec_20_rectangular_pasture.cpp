#include<algorithm>
#include<iostream>

using namespace std;

typedef pair<int, int> pii;

int n, dp[2501][2501];

long long ans = 1;

pii cows[2500];

int cpr(pii a, pii b) {
	return a.second < b.second;
}

int sum(int x1, int y1, int x2, int y2) {
	return dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> cows[i].first >> cows[i].second;

	sort(cows, cows + n);

	for (int i = 0; i < n; i++)
		cows[i].first = i + 1;

	sort(cows, cows + n, cpr);

	for (int i = 0; i < n; i++)
		cows[i].second = i + 1;

	for (int i = 0; i < n; i++)
		dp[cows[i].first][cows[i].second] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			ans += sum(0, i, min(cows[i].first, cows[j].first) - 1, j) * sum(max(cows[i].first, cows[j].first) - 1, i, n - 1, j);

	cout << ans << "\n";
}
