#include<cstring>
#include<iostream>

using namespace std;

typedef pair<int, int> pii;

int n, c, dp[5000], ans = 0;

pii a[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	memset(dp, -1, sizeof dp);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
		for (int j = c; j >= 0; j--)
			if (j - a[i].first >= 0 && dp[j - a[i].first] >= 0)
				dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);

	int ans = 0;
	for (int i = 0; i <= c; i++)
		ans = max(ans, dp[i]);

	cout << ans << "\n";
}
