#include<fstream>

using namespace std;

ifstream in("feast.in");
ofstream out("feast.out");

int t, a, b, dp[2][5000001];

int main() {
	in >> t >> a >> b;
	
	dp[0][0] = 1;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= t; j++) {
			if (!dp[i][j]) continue;

			if (a + j <= t) dp[i][a + j] = 1;
			if (b + j <= t) dp[i][b + j] = 1;
			if (!i) dp[1][j / 2] = 1;
		}
	}

	for (int i = t; i >= 0; i--) {
		if (dp[1][i]) {
			out << i << "\n";
			return 0;
		}
	}
}
