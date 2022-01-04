#include<fstream>

using namespace std;

ifstream in("paintbarn.in");
ofstream out("paintbarn.out");

int n, k, dp[1001][1001], ans = 0;

int main() {
	in >> n >> k;

	while (n--) {
		int x1, y1, x2, y2;
		in >> x1 >> y1 >> x2 >> y2;

		dp[x1][y1]++;
		dp[x2][y2]++;
		dp[x1][y2]--;
		dp[x2][y1]--;
	}

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (i) dp[i][j] += dp[i - 1][j];
			if (j) dp[i][j] += dp[i][j - 1];
			if (i && j) dp[i][j] -= dp[i - 1][j - 1];
			ans += dp[i][j] == k;
		}
	}

	out << ans << "\n";
}
