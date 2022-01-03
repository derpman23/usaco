#include<fstream>

using namespace std;

ifstream in("hps.in");
ofstream out("hps.out");

int n, dp[100001][3], ans = 0;

int main() {
	in >> n;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][2];

		char c;
		in >> c;

		if (c == 'H') dp[i][0]++;
		else if (c == 'P') dp[i][1]++;
		else dp[i][2]++;
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				ans = max(ans, dp[i][j] + dp[n][k] - dp[i][k]);

	out << ans << "\n";
}
