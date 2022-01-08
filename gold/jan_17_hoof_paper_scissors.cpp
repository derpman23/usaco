#include<fstream>

using namespace std;

ifstream in("hps.in");
ofstream out("hps.out");

int n, k, m[100000], dp[100001][25][3], ans = 0;

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++) {
		char c;
		in >> c;
		if (c == 'P') m[i] = 1;
		else if (c == 'S') m[i] = 2;
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b <= k; b++) {
			for (int c = 0; c < 3; c++) {
				dp[a][b][c] += c == m[a];
				dp[a + 1][b + 1][0] = max(dp[a + 1][b + 1][0], dp[a][b][c]);
				dp[a + 1][b + 1][1] = max(dp[a + 1][b + 1][1], dp[a][b][c]);
				dp[a + 1][b + 1][2] = max(dp[a + 1][b + 1][2], dp[a][b][c]);
				dp[a + 1][b][c] = max(dp[a + 1][b][c], dp[a][b][c]);
			}
		}
	}

	for (int i = 0; i < 3; i++)
		ans = max(ans, dp[n - 1][k][i]);

	out << ans << "\n";
}
