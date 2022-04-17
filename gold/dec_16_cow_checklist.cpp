#include<cstring>
#include<fstream>

using namespace std;

typedef pair<int, int> pii;

ifstream in("checklist.in");
ofstream out("checklist.out");

int dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int n, m, dp[1001][1001][2];

pii cows[1001][2];

int main() {
	in >> n >> m;

	for (int i = 1; i <= n; i++)
		in >> cows[i][0].first >> cows[i][0].second;

	for (int i = 1; i <= m; i++)
		in >> cows[i][1].first >> cows[i][1].second;

	memset(dp, 127, sizeof dp);
	dp[1][0][0] = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				if ((!k & !i) | (k & !j))continue;
				pii c;
				if (k)c = cows[j][1];
				else c = cows[i][0];
				if (i < n)dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(cows[i + 1][0], c));
				if (j < m)dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(cows[j + 1][1], c));
			}
		}
	}

	out << dp[n][m][0] << "\n";
}
