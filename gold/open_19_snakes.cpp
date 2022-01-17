#include<fstream>

using namespace std;

ifstream in("snakes.in");
ofstream out("snakes.out");

int n, k, a[401], dp[401][400], snakes = 0, mx = 0;

int main() {
	in >> n >> k;

	for (int i = 1; i <= n; i++) {
		in >> a[i];
		snakes += a[i];
		mx = max(mx, a[i]);
		dp[i][0] = mx * i;

		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i][0];
			int high = a[i];

			for (int s = i - 1; s >= 0; s--) {
				dp[i][j] = min(dp[i][j], dp[s][j - 1] + high * (i - s));
				high = max(high, a[s]);
			}
		}
	}

	out << dp[n][k] - snakes << "\n";
}
