#include<cstring>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("time.in");
ofstream out("time.out");

int n, m, c, p[1000], dp[1001][1000], ans = 0;

vector<int> adj[1000];

int main() {
	in >> n >> m >> c;

	for (int i = 0; i < n; i++)
		in >> p[i];

	for (int i = 0; i < m; i++) {
		int a, b; in >> a >> b;
		adj[--a].push_back(--b);
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < n; j++)
			if (dp[i][j] != -1)
				for (int k : adj[j])
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + p[k]);
		ans = max(ans, dp[i][0] - c * i * i);
	}

	out << ans << "\n";
}
