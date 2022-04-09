#include<iostream>
#include<numeric>

using namespace std;

int n, sum, a[50], dp[50][10000]{ {1} };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	sum = (n * (n + 1)) / 2;

	if (sum % 2) { cout << "0\n"; return 0; }
	iota(a, a + n, 1);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sum; j++)
			dp[i + 1][j + a[i]] += dp[i][j], dp[i + 1][j] += dp[i][j];

	cout << dp[n - 1][sum / 2] << '\n';
}
