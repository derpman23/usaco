#include<fstream>

using namespace std;

ifstream in("bcount.in");
ofstream out("bcount.out");

int n, q, dp[100001][3], cow;

int main() {
	in >> n >> q;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][2];
		in >> cow;

		dp[i][cow - 1]++;
	}

	while (q--) {
		int a, b;
		in >> a >> b;

		out << dp[b][0] - dp[a - 1][0] << " " << dp[b][1] - dp[a - 1][1] << " " << dp[b][2] - dp[a - 1][2] << "\n";
	}
}
