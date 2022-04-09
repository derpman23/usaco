#include<iostream>

using namespace std;

int n, a[20001]{ -0x7fffffff }, dp[20001], ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);

	cout << ans << '\n';
}
