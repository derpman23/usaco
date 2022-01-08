#include<cstring>
#include<fstream>
#include<numeric>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

ifstream in("ccski.in");
ofstream out("ccski.out");

int m, n, g[500][500], d, v[500][500], h1 = 1000000000, h2 = 0, ans = 0;

vector<pii> w;

void dfs(int x, int y, int h) {
	if (x < 0 || x >= n || y < 0 || y >= n || v[x][y] || abs(h - g[x][y]) > d) return;
	v[x][y] = 1;

	dfs(x - 1, y, g[x][y]);
	dfs(x + 1, y, g[x][y]);
	dfs(x, y - 1, g[x][y]);
	dfs(x, y + 1, g[x][y]);
}

int works() {
	for (int i = 0; i < m; i++)
		memset(v[i], 0, sizeof(int) * n);

	dfs(w[0].first, w[0].second, g[w[0].first][w[0].second]);

	for (pii p : w)
		if (!v[p.first][p.second])
			return 0;
	
	return 1;
}

int main() {
	in >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			in >> g[i][j];
			h1 = min(h1, g[i][j]), h2 = max(h2, g[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int b;
			in >> b;
			if (b) w.push_back({ i, j });
		}
	}

	int low = 0, high = h2 - h1;

	while (low <= high) {
		d = (low + high) / 2;

		if (works()) ans = d, high = d - 1;
		else low = d + 1;
	}

	out << ans << "\n";
}
