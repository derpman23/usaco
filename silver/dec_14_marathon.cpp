#include<cstring>
#include<fstream>

using namespace std;

typedef pair<int, int> pii;

ifstream in("marathon.in");
ofstream out("marathon.out");

int n, k, dp[501][501];

pii cp[500];

int main() {
	in >> n >> k;

	for (int i = 0; i < n; i++)
		in >> cp[i].first >> cp[i].second;

	memset(dp, 127, sizeof dp);
	dp[0][0] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			for (int a = i + 1; a < n && j + a - i - 1 <= k; a++)
				dp[a][j + a - i - 1] = min(dp[a][j + a - i - 1], dp[i][j] + abs(cp[i].first - cp[a].first) + abs(cp[i].second - cp[a].second));

	out << dp[n - 1][k] << '\n';
}
